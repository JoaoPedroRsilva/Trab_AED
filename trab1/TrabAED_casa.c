#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void allLowerCase(char* licensePlate, int* letras);
char* shortestCompletingWord(char* licensePlate, char** words, int wordsSize);

int main() {
    // Exemplo 1
    char licensePlate1[] = "1s3 PSt";
    char* words1[] = {"step", "steps", "stripe", "stepple"};
    int size1 = sizeof(words1) / sizeof(words1[0]);
    
    char* resultado1 = shortestCompletingWord(licensePlate1, words1, size1);
    printf("Exemplo 1 - Resultado esperado: steps | Resultado obtido: %s\n", resultado1);

    // Exemplo 2 
    char licensePlate2[] = "1s3 456";
    char* words2[] = {"looks", "pest", "stew", "show"};
    int size2 = sizeof(words2) / sizeof(words2[0]);
    
    char* resultado2 = shortestCompletingWord(licensePlate2, words2, size2);
    printf("Exemplo 2 - Resultado esperado: pest | Resultado obtido: %s\n", resultado2);

    return 0;
}
//
void allLowerCase ( char* licensePlate, int* letras ) // Passa para minusculo e armazena a frequencia
{
     int tamLicensePlate = strlen( licensePlate );
    for( int i = 0; i < tamLicensePlate; i++ ) // O(L)
    {
        if( ( 'A' <= licensePlate[i] ) && ( licensePlate[i] <= 'Z' ) )
        {
            licensePlate[i] = licensePlate[i] + 32;
        }
    }
    // Tabela ASCII: A = 65 , Z = 90 | a = 97 , z = 122
   
    for( int i = 0; i < tamLicensePlate; i++ )
    {
        if( 97 <= licensePlate[i] && licensePlate[i] <= 122 )
        letras[licensePlate[i] - 97]++; // Frequencia de letras
    }
}
char* shortestCompletingWord( char* licensePlate, char** words, int wordsSize ) 
{
    int letrasTemp[26] = {0};
    int letras[26] = {0};
    allLowerCase( licensePlate, letras );
// *****
    int* nDeIguais;
    nDeIguais = (int*) malloc(sizeof(int) * wordsSize);
    if( !nDeIguais )
    {
        printf("Erro ao alocar memoria.");
        exit(1);
    }
    memset( nDeIguais, 0, sizeof(int) * wordsSize );
    
    int okCount = 0;
    int* vetorDeOk;
    vetorDeOk = (int*) malloc(sizeof(int) * wordsSize);
    if(!vetorDeOk)
    {
        printf("Erro ao alocar memoria.");
        exit(1);
    }
    memset(vetorDeOk, 0, sizeof(int) * wordsSize);
// *****
    for( int i = 0; i < wordsSize; i++ ) // O(N x W)
    {
        int Ok = 1; // Flag para ver se a palavra tem frequencia correta de caracteres
        memset( letrasTemp, 0, sizeof( letrasTemp ) ); // Zerando o letrasTemp para cada nova palavra
        for( int j = 0; words[i][j] != '\0'; j++ ) // Preencher o letrasTemp com as palavras de words
        {
            letrasTemp[words[i][j] - 97]++;
        }
        for( int j = 0; j < 26; j++ ) // Compara letras com letrasTemp
        {
            if( letras[j] > letrasTemp[j] ) // Se a frequencia da licensePlate for maior marca a flag e sai do loop
            {
                Ok = 0;
                break;
            }
        }
        if(Ok == 0) continue;

        vetorDeOk[okCount++] = i; // armazena o indice da palavra apenas se a flag OK esta verdadeira
    }
    int menorPalavra = 1000; // inicializado com um indice muito maior que qualquer palavra possivel de input
    int menorPalavraIndice = 0;
    for( int i = 0; i < okCount; i++ ) // O (N x W) no pior caso
    {
        int wordsLen = strlen(words[vetorDeOk[i]]);
        if( wordsLen < menorPalavra) // Logica para pegar a menor palavra
        {
            menorPalavra = wordsLen;
            menorPalavraIndice = vetorDeOk[i]; 
        }
    }
    free(vetorDeOk);
    free(nDeIguais);
    return words[menorPalavraIndice];
}

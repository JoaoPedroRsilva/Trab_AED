#include <stdio.h>
#include <string.h>

char* shortestCompletingWord(char* licensePlate, char** words, int wordsSize);

int main() {
    // ----------- Exemplo 1 -----------
    char licensePlate1[] = "1s3 PSt";
    char* words1[] = {"step", "steps", "stripe", "stepple"};
    int size1 = sizeof(words1) / sizeof(words1[0]);

    char* resultado1 = shortestCompletingWord(licensePlate1, words1, size1);
    printf("Exemplo 1 - Esperado: steps | Obtido: %s\n", resultado1);

    // ----------- Exemplo 2 -----------
    char licensePlate2[] = "1s3 456";
    char* words2[] = {"looks", "pest", "stew", "show"};
    int size2 = sizeof(words2) / sizeof(words2[0]);

    char* resultado2 = shortestCompletingWord(licensePlate2, words2, size2);
    printf("Exemplo 2 - Esperado: pest | Obtido: %s\n", resultado2);

    return 0;
}

char* shortestCompletingWord(char* licensePlate, char** words, int wordsSize) {
    

    int equalLetters[5] = {0};
    int wordSize[4] = {0};
    for(int i = 0; licensePlate[i] != '\0'; i++)
    {
        int j = 0; int k = 0; 
        while(j < wordsSize && words[j][k] != '\0')
        {
            if(licensePlate[i] == words[j][k])
            {
                equalLetters[j]++;
            }
            k++;
            wordSize[j]++;
            if(words[j][k] == '\0')
            {
                j++;
                k = 0;
            }
        }
    }
    int biggest = equalLetters[0];
    int biggestIndex = 0;
    for(int i = 1; i < wordsSize; i++)
    {
        if(biggest < equalLetters[i])
        {
            biggest = equalLetters[i];
            biggestIndex = i;
        }
    }
    int shortestWord = wordSize[0];
    int shortestIndex = 0;
    for(int i = 1; i < wordsSize; i++)
    {
        if(shortestWord > wordSize[i])
        {
            shortestWord = wordSize[i];
            shortestIndex = i;
        }
    }
    if(words[biggestIndex] == words[shortestIndex])
    {
        return words[biggestIndex];
    }
    return words[biggestIndex];
}
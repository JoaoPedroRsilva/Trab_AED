int maximumGain(char* s, int x, int y) {    
    int result = 0;
    char *stack = ( char* ) malloc( sizeof( char ) * strlen( s ) );
    if( !stack ){
        printf("**** Malloc Error.\n");
        exit( 1 );
    }    

    int sLength = strlen( s );
    int top = 0;
    int k = 0;
    for( int i = 0; i < sLength; i++ ){
        stack[top] = s[i];
        top++;
        if( top < sLength ){
            if( x < y ){
            while( top >= 2 && stack[top - 1] == 'a' && stack[top - 2] == 'b' ){ // BA
                top -= 2;
                result += y;
            }
            } else{
            while( top >= 1 && stack[top - 1] == 'b' && stack[top - 2] == 'a'){ // AB
                top -= 2;
                result += x;
            }
            }
        }
    }
    if( x < y && top > 1){
    while( top >= 0 ){
                //top--;
                s[k] = stack[top--]; 
                k++;
                while( k >= 2 && s[k - 1] == 'a' && s[k - 2] == 'b' ){
                    k -= 2;
                    result += x;
                }
            }
    // } else if( x > y && top > 1){
    // while( top >= 0 ){
    //     //top--;
    //     s[k] = stack[top--]; 
    //     k++;
    //     while( k >= 2 && s[k - 1] == 'b' && s[k - 2] == 'a' ){
    //         k -= 2;
    //         result += y;
    //     }
    // }
    }

    return result;
}
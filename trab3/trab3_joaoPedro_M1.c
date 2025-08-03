int ACTG( int numsSize, int subSize ){
    int total = numsSize - 1;
    int result = 1;
    
    for( int i = 0; i < subSize; i++ ){
        result *= ( total - i )/ ( i + 1 );
    }

    return result;
}


int numOfWays(int* nums, int numsSize) {
    int *subArrayLess = ( *int ) malloc(sizeof( int ) * numsSize );
    if( !subArray ) exit( 1 );

    int *subArrayMore = ( *int ) malloc(sizeof( int ) * numsSize );
    if( !subArray ) exit( 1 );
    int permutations = 0;

    int lessSize = 0;
    for( int i = 1; i < numsSize; i++ ){
        if( nums[i] < nums[0] && nums[i] != 0 ){
            subArrayLess[lessSize++] = nums[i];
        }
    }
    permutations *= ACTG( subArrayLess, numsSize );
    numOfWays( subArrayLess, numsSize );
    moreSize = 0;
    for( int i = 1; i < numsSize; i++ ){
        if( nums[i] > nums[0] && nums[i] != 0 ){
            subArrayMore[moreSize++] = nums[i];
        }
    }
    permutations *= ACTG( subArrayMore, numsSize );
    numberOfWays( subArrayMore, numsSize );


    return permutations;
}
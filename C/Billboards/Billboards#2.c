#include <stdio.h>
#include <stdlib.h>

int valid(int mid, int array[], int i, int b)
{
    int start = array[0];
    int counter = 1;

    for ( int y = 1 ; y < i ; y++ )
    {
        if ( (array[y] - start) >= mid )
        {
            start = array[y];
            counter++;
            if (counter == b)
                return 1;
        }
    }
    return 0;
}

int binarysearch (int array[], int i, int b)
{
    int lo = 0;
    int hi = array[i-1];
    while ( (hi-lo) > 1 )
    {
        int mid = (hi-lo) - 1;
        int value = valid(mid,array,i,b);
        if ( value == 1 )
            lo = mid;
        else
            hi = mid;
    }
    return lo;
}

int main()
{
    int * array = (int*) malloc(sizeof(array[0]) * 1000000);
    int billboards;
    char c,c1;

    printf("Suitable positions:\n");
    if ( scanf(" %c",&c1) == 1 )
    {
        if ( c1 != '{' )
        {
            printf("Invalid input.\n");
            return 0;
        }
    }
    else
    {
        printf("Invalid input.\n");
        return 0;
    }

    int i = 0;
    while (1)
    {
        if ( scanf( " %d %c",&array[i],&c ) == 2 )
        {
            if ( array[i] >= 0 )
                i++;
            else
            {
                printf("Invalid input.\n");
                return 0;
            }
            if ( c == '}' )
                break;
            else if ( c == ',' )
                continue;
            else
            {
                printf("Invalid input.\n");
                return 0;
            }
        }
        else
        {
            printf("Invalid input.\n");
            return 0;
        }

    }

    int tmp;
    for ( int j = 0 ; j <= i ; j++ )
    {
        for ( int k = (j+1) ; k <= (i-1) ; k++ )
        {
            if( array[j] > array[k] )
            {
                tmp = array[k];
                array[k] = array[j];
                array[j] = tmp;
            }
        }
    }

    printf("# of billboards:\n");
    int scan;
    while ( (scan = scanf(" %d", &billboards)) != EOF )
    {
        if ( scan == 0 || billboards < 0)
        {
            printf("Invalid input.\n");
            return 0;
        }
        if ( billboards == 0 || billboards == 1 )
        {
            printf("Distance: inf\n");
            billboards = 0;
            continue;
        }
        if ( billboards == 2 && i < 2 )
        {
            printf("N/A\n");
            billboards = 0;
            continue;
        }
        if ( billboards == 2 )
        {
            printf("Distance: %d\n",(array[i-1]-array[0]));
            billboards = 0;
            continue;
        }
        if ( billboards > i )
        {
            printf("N/A\n");
            billboards = 0;
            continue;
        }
        int dist = binarysearch(array,i,billboards);
        printf("Distance: %d\n",dist);
        billboards = 0;
    }

    free(array);
    return 0;
}
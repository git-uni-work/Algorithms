#include <stdio.h>
#include <stdlib.h>

int binarysearch (int a[], int n, int x)
{
    int l = 0;
    int h = n;
    while ( l < h )
    {
        int mid = (l + h) / 2;
        if (x <= a[mid])
            h = mid;
        else
            l = mid + 1;
    }
    return l;
}

int main()
{
    int * array = (int*) malloc(sizeof(array[0]) * 1000000);
    int length,distance;
    char c,c1,c2;

    printf("Suitable positions:\n");
    if ( scanf(" %d %c %c", &length,&c1,&c2 ) == 3 )
    {
        if ( ( length <= 0 ) || ( c1 != ':' ) || ( c2 != '{' ) )
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
            if ( ( array[i] <= (length - 1) ) && ( array[i] >= 1 ) )
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
            /*if ( i > 1000000 )
            {
                printf("Invalid input.\n");
                return 0;
            }*/
        }
        else
        {
            printf("Invalid input.\n");
            return 0;
        }

    }

    array[i] = length;
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

    printf("Distances:\n");
    while ( scanf(" %d", &distance) != EOF )
    {
        if ( distance == 0 )
        {
            printf("Invalid input.\n");
            return 0;
        }
        int dist = distance;
        int counter = 0;

            for ( int x = 0 ; x <= i ; x++ )
            {
                if ( distance < array[0] )
                {
                    printf("N/A\n");
                    break;
                }
                if ( distance >= length )
                {
                    printf("Billboards: 0\n");
                    break;
                }

                int current = array[x];
                int next = array[x+1];
                if ( dist > current && dist > next )
                {
                    current = next;
                    next = array[x+2];
                    continue;
                }
                else if ( dist >= next )
                {
                    counter++;
                    dist = distance + next;
                    if ( dist < array[x+2] )
                    {
                        printf("N/A\n");
                        break;
                    }
                    if ( dist >= length )
                    {
                        printf("Billboards: %d\n",counter);
                        distance = 0;
                        break;
                    }
                }
                else
                {
                    counter++;
                    dist = distance + current;
                    if ( dist < array[x+1] )
                    {
                        printf("N/A\n");
                        break;
                    }
                    if ( dist >= length )
                    {
                        printf("Billboards: %d\n",counter);
                        distance = 0;
                        break;
                    }
                }
            }
    }

    free(array);
    return 0;
}
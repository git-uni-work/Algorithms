#include <stdio.h>

int l(int x,int y)
{
    int digits;
    digits = !x;
    for (int i = x ; i < y+1 ; i++ )
    {
        int z = i;
        while ( z != 0 )
        {
            z /= 2;
            digits++;
        }
    }
    return digits;
}
int z(int x,int y)
{
    int zeros;
    zeros = !x;
    for (int i = x ; i < y+1 ; i++ )
    {
        int z = i;
        while ( z != 0)
        {
            if ( (z % 2) == 0 )
            {
                zeros++;
            }
            z /= 2;
        }
    }
    return zeros;
}
int s(int x,int y)
{
    int c1,c2;
    c1 = 0;
    c2 = !x;
    for (int i = x ; i < y+1 ; i++ )
    {
        int z = i;
        while ( z != 0)
        {
            if ( (z % 2) == 0 )
            {
                c1++;
                if (c2 < c1)
                    c2 = c1;
            }
            else
            {
                c1 = 0;
            }
            z /= 2;
        }
        c1 = 0;
    }
    return c2;
}

int main()
{
    int lo,hi,digits,zeros,seq;
    char mode;

    printf("Enter the interval:\n");
    if ( scanf(" < %d ; %d > %c",&lo,&hi,&mode) == 3 )
    {
        if( lo < 0 || hi < 0 ||lo > hi || (mode != 'l' && mode != 'z' && mode != 's') )
        {
            printf("Invalid input.\n");
            return 0;
        }
        if ( mode == 'l' )
        {
            digits = l(lo,hi);
            printf("Digits: %d\n",digits);
        }
        else if ( mode == 'z' )
        {
            zeros = z(lo,hi);
            printf("Zeros: %d\n",zeros);
        }
        else
        {
            seq = s(lo,hi);
            printf("Sequence: %d\n",seq);
        }
    }
    else
    {
        printf("Invalid input.\n");
        return 0;
    }
    return 0;
}
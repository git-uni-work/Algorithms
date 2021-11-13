#include <stdio.h>

int l(int x,int y,int b)
{
    int digits;
    digits = !x;
    for (int i = x ; i <= y ; i++ )
    {
        int z = i;
        while ( z != 0 )
        {
            z /= b;
            digits++;
        }
    }
    return digits;
}
int z(int x,int y,int b)
{
    int zeros;
    zeros = !x;
    for (int i = x ; i <= y ; i++ )
    {
        int z = i;
        while ( z != 0)
        {
            if ( (z % b) == 0 )
            {
                zeros++;
            }
            z /= b;
        }
    }
    return zeros;
}
int s(int x,int y,int b)
{
    int c1,c2;
    c1 = 0;
    c2 = !x;
    for (int i = x ; i <= y ; i++ )
    {
        int z = i;
        while ( z != 0)
        {
            if ( (z % b) == 0 )
            {
                c1++;
                if (c2 < c1)
                    c2 = c1;
            }
            else
            {
                c1 = 0;
            }
            z /= b;
        }
        c1 = 0;
    }
    return c2;
}

int main()
{
    int lo,hi,digits,zeros,seq;
    char mode,r;

    printf("Enter the intervals:\n");
    while ( scanf(" %c", &r) != EOF )
    {
        int radix = 10;
        if ( r == 'r' )
        {
            if ( scanf(" %d : < %d ; %d > %c", &radix,&lo,&hi,&mode) == 4 )
            {
                if( radix > 36 || radix < 2 || lo < 0 || hi < 0 ||lo > hi || (mode != 'l' && mode != 'z' && mode != 's') )
                {
                    printf("Invalid input.\n");
                    return 0;
                }
                if ( mode == 'l' )
                {
                    digits = l(lo,hi,radix);
                    printf("Digits: %d\n",digits);
                }
                else if ( mode == 'z' )
                {
                    zeros = z(lo,hi,radix);
                    printf("Zeros: %d\n",zeros);
                }
                else
                {
                    seq = s(lo,hi,radix);
                    printf("Sequence: %d\n",seq);
                }
            }
            else
            {
                printf("Invalid input.\n");
                return 0;
            }
        }
        else if ( scanf(" %d ; %d > %c", &lo,&hi,&mode) == 3 )
        {
            if( r != '<' || lo < 0 || hi < 0 ||lo > hi || (mode != 'l' && mode != 'z' && mode != 's') )
            {
                printf("Invalid input.\n");
                return 0;
            }
            if ( mode == 'l' )
            {
                digits = l(lo,hi,radix);
                printf("Digits: %d\n",digits);
            }
            else if ( mode == 'z' )
            {
                zeros = z(lo,hi,radix);
                printf("Zeros: %d\n",zeros);
            }
            else
            {
                seq = s(lo,hi,radix);
                printf("Sequence: %d\n",seq);
            }
        }
        else
        {
            printf("Invalid input.\n");
            return 0;
        }
    }
    return 0;

}
#include <stdio.h>
#include <string.h>

int main()
{
    int d1,d2,f,p;
    char c;
    char r[1000];

    printf("Dimensions:\n");
    if ( scanf ( " %d %d",&d1,&d2 ) == 2 )
    {
        if ( d1 <= 0 || d2 <= 0 )
        {
            printf("INVALID INPUT.\n");
            return 0;
        }
    }
    else
    {
        printf("INVALID INPUT.\n");
        return 0;
    }
    char array[d1][d2][11];
    for ( int i = 0 ; i < d1 ; i++ )
    {
        for ( int x = 0 ; x < d2 ; x++ )
        {
            for ( int y = 0 ; y < 11 ; y++ )
                array[i][x][y] = '0';
        }
    }


    printf("Requests:\n");
    while (1)
    {
        if ( scanf ( " %c",&c ) == 1 )
        {
            if ( c == '+' )
            {
                if ( scanf ( " %d %d %s",&f,&p,r ) == 3)
                {
                    if ( f < 0 || p < 0 || f >= d1 || p >= d2 )
                    {
                        printf("INVALID INPUT.\n");
                        break;
                    }
                    else if ( strlen(r) > 10 )
                    {
                        printf("INVALID INPUT.\n");
                        break;
                    }
                    else
                    {
                        if ( array[f][p][0] == '0' )
                        {
                            strcpy(array[f][p],r);
                            printf("OK\n");
                            /*for ( int i = f ; i < d1 ; i++ )
                            {
                                for ( int x = p ; x < d2 ; x++ )
                                {
                                    for ( int y = 0 ; y < 11 ; y++ )
                                        printf("array [%d][%d][%d] = %c\n",i,x,y,array[i][x][y]);
                                }
                            }*/
                            continue;
                        }
                        else
                        {
                            printf("USED BY %s\n",array[f][p]);
                            continue;
                        }
                    }

                }
                else
                {
                    printf("INVALID INPUT.\n");
                    break;
                }

            }
            else if ( c == '-' )
            {
                if ( scanf (" %s", r ) == 1 )
                {
                    if ( strlen(r) > 10 )
                    {
                        printf("INVALID INPUT.\n");
                        break;
                    }
                    else
                    {
                        int flag = 0;
                        for ( int i = 0 ; i < d1 ; i++ )
                        {
                            if ( flag == 1 )
                                break;
                            for ( int x = 0 ; x < d2 ; x++ )
                            {
                                if (! ( strcmp(r,array[i][x]) ) )
                                {
                                    printf("OK\n");
                                    for ( int y = 0 ; y < 11 ; y++ )
                                    {
                                        array[i][x][y] = '0';
                                    }
                                    flag = 1;
                                    break;
                                }
                            }
                        }
                        if ( flag == 0 )
                            printf("NOT FOUND\n");
                        continue;
                    }
                }
                else
                {
                    printf("INVALID INPUT.\n");
                    break;
                }
            }
            else
            {
                printf("INVALID INPUT.\n");
                break;
            }
        }
        else
        {
            printf("INVALID INPUT.\n");
            break;
        }
    }

    return 0;
}
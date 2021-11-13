#include <stdio.h>
#include <string.h>

int main()
{
    char floor,pp;
    char c,reg[20];
    int total,fc,pc,flag;

    printf("Dimensions:\n");
    scanf(" %c %c",&floor,&pp);
    if ( floor > 90 || floor < 65 || pp > 122 || pp < 97 )
    {
        printf("INVALID INPUT\n");
        return 0;
    }
    floor -= 64;
    pp -= 96;
    total = floor * pp;

    char carpark[floor][pp][11];
    for ( int x = 0 ; x < floor ; x++ )
        for ( int y = 0 ; y < pp ; y++ )
            for ( int z = 0 ; z < 11 ; z++ )
                carpark[x][y][z] = '0';

        /*for ( int x = 0 ; x < floor ; x++ )
            for ( int y = 0 ; y < pp ; y++ )
            {
                printf("\n");
                for ( int z = 0 ; z < 10 ; z++ )
                    printf("array[%d][%d][%d] = %c\n",x,y,z,carpark[x][y][z]);
            }*/

    int time[floor][pp];
    for ( int x = 0 ; x < floor ; x++ )
        for ( int y = 0 ; y < pp ; y++ )
           time[x][y] = 0;

    fc = 0;
    pc = 0;
    printf("Requests:\n");
    while (1)
    {
        scanf(" %c %s",&c,reg);
        if ( c == '+' )
        {
            if ( fc < floor && pc < pp && total > 0 )
            {
                if ( strlen(reg) > 10 )
                {
                    printf("INVALID INPUT\n");
                    break;
                }
                int maxx = 0;
                int maxy = 0;
                for ( int i = 0; i < floor ; i++ )
                {
                    for ( int j = 0; j < pp ; j++ )
                    {
                        if ( time[maxx][maxy] < time[i][j] )
                        {
                            maxx = i;
                            maxy = j;
                        }
                    }
                }
//                printf("Max time =  %d @ %c%c\n",time[maxx][maxy],maxx+65,maxy+97);

                fc = maxx;
                pc = maxy;
                strcpy(carpark[fc][pc],reg);

                for ( int x = 0 ; x < floor ; x++ )
                    for ( int y = 0  ; y < pp ; y++ )
                    {
                        if ( carpark[x][y][0] == '0' )
                            time[x][y]++;
                        else
                            time[x][y] = 0;
                    }
                /*for ( int x = 0 ; x < floor ; x++ )
                    for ( int y = 0 ; y < pp ; y++ )
                        printf("time[%c][%c] = %d\n",x+65,y+97,time[x][y]);*/

                pc++;
                total--;
                printf("Position: %c%c, remains: %d\n",fc+65,pc+96,total);
                continue;
            }
            else if ( fc < floor && pc == pp && total > 0)
            {
                if ( strlen(reg) > 10 )
                {
                    printf("INVALID INPUT\n");
                    break;
                }

                int maxx = 0;
                int maxy = 0;
                for ( int i = 0; i < floor ; i++ )
                {
                    for ( int j = 0; j < pp ; j++ )
                    {
                        if ( time[maxx][maxy] < time[i][j] )
                        {
                            maxx = i;
                            maxy = j;
                        }
                    }
                }
//                printf("Max time =  %d @ %c%c\n",time[maxx][maxy],maxx+65,maxy+97);

                fc = maxx;
                pc = maxy;
                strcpy(carpark[fc][pc],reg);

                for ( int x = 0 ; x < floor ; x++ )
                    for ( int y = 0 ; y < pp ; y++ )
                    {
                        if ( carpark[x][y][0] == '0' )
                            time[x][y]++;
                        else
                            time[x][y] = 0;
                    }
                /*for ( int x = 0 ; x < floor ; x++ )
                    for ( int y = 0 ; y < pp ; y++ )
                        printf("time[%c][%c] = %d\n",x+65,y+97,time[x][y]);*/

                total--;
                printf("Position: %c%c, remains: %d\n",fc+65,pc+97,total);
                pc++;
                continue;
            }
            else if ( total <= 0 )
            {
                printf("Car Park is FULL\n");
                continue;
            }
        }
        else if ( c == '-' )
        {
            flag = 0;
            for ( int x = 0 ; x < floor ; x++ )
            {
                if ( flag == 1 )
                    break;
                for ( int y = 0 ; y < pp ; y++ )
                {
                    if ( flag == 1 )
                        break;
                    for ( int z = 0 ; z < 10 ; z++ )
                    {
                        if ( ! ( strcmp(carpark[x][y] , reg) ) )
                        {
                            printf("%s left parking spot %c%c\n",reg,x+65,y+97);
                            flag = 1;
                            total++;
                            for ( int r = 0 ; r < 10 ; r++ )
                            {
                                carpark[x][y][r] = '0';
                            }
                            for ( int x = 0 ; x < floor ; x++ )
                                for ( int y = 0 ; y < pp ; y++ )
                                {
                                    if ( carpark[x][y][0] == '0' )
                                        time[x][y]++;
                                    else
                                        time[x][y] = 0;
                                }
                            break;
                        }
                    }
                }
            }
            if ( flag == 0 )
            {
                printf("Car NOT FOUND\n");
            }
        }
        else
        {
            printf("INVALID INPUT\n");
            break;
        }
    }
    return 0;
}


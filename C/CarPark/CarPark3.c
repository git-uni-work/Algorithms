#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct park
{
    char reg[20];
    int time;
    int days;
}park;

int main()
{
    char col,min1,min2,alg;
    int i = 0,hour;
    int time;
    char reg[20];
    int tolls[3];
    tolls[0] = 30;// between 30 & 60
    tolls[1] = 40;// for every hour after the 1st 60 minutes
    tolls[2] = 1000;// every hour after 24 hours

    park * parking = (park*) malloc (sizeof(park)*10000);
    printf("Requests:\n");
    while ( 1 )
    {
        int fee = 0;
        int mins,timeelapsed;
        int flag = 0;
        scanf(" %d %c %c%c %c",&hour,&col,&min1,&min2,&alg);
        min1 -= 48;
        min2 -= 48;
        switch(alg)
        {
            case('='):
                if ( hour == 0 && min1 == 0 && min2 == 0 )
                {
                    for ( int x = 0 ; x < i ; x++ )
                        parking[x].days++;

                    printf("24 hours passed\n");
                    printf("ISSA NEW DAY\n");
                    for ( int x = 0 ; x < i ; x++ )
                        printf("%s Time Start = %d Days elapsed = %d\n",parking[x].reg,parking[x].time,parking[x].days);
                }
                continue;

            case('+'):
                scanf(" %s",reg);
                if ( hour <= 24 && hour > 0 && min1 <= 6 && min2 <= 9 && min1 >= 0 && min2 >= 0 )
                {
                    strcpy(parking[i].reg,reg);
                    time = hour * 60;
                    time += min1 * 10;
                    time += min2;
                    parking[i].time = time;
                    printf("CAR ADDED\n");
                    i++;
                    for ( int x = 0 ; x < i ; x++ )
                        printf("%s Time Start = %d Days elapsed = %d\n",parking[x].reg,parking[x].time,parking[x].days);
                }
                break;

            case('-'):
                scanf(" %s",reg);
                if (hour <= 24 && hour > 0 && min1 <= 6 && min2 <= 9 && min1 >= 0 && min2 >= 0 )
                {
                    for ( int x = 0 ; x < i ; x++ )
                    {
                        if ( !( strcmp(parking[x].reg,reg) ) )
                        {
                            flag = 1;
                            i--;
                            mins = hour * 60;
                            mins += min1 * 10;
                            mins += min2;
                            timeelapsed = mins - parking[x].time;

                            printf("%s time elapsed = %d\n",parking[x].reg,timeelapsed);

                            for ( int x = 0 ; x < i ; x++ )
                                printf("%s Time Start = %d Days elapsed = %d\n",parking[x].reg,parking[x].time,parking[x].days);

                            if ( parking[x].days >= 1 && timeelapsed > 0 )
                            {
                                fee += parking[x].days * tolls[2];
                                printf("Car fee = %d\n",fee);
                                continue;
                            }
                            else if (  parking[x].days == 1 && timeelapsed <= 0 )
                            {
                                fee += ((1440 + timeelapsed)/60) * tolls[1];
                                printf("Car fee = %d\n",fee);
                                continue;
                            }
                            else if ( timeelapsed > 60 && timeelapsed <= 1440 )
                            {
                                fee += (timeelapsed/60) * tolls[1];
                                printf("Car fee = %d\n",fee);
                                continue;
                            }
                            else if ( timeelapsed > 30 && timeelapsed <= 60 )
                            {
                                fee += tolls[0];
                                printf("Car fee = %d\n",fee);
                                continue;
                            }
                            else
                            {
                                fee = 0;
                                printf("Car fee = %d\n",fee);
                                continue;
                            }
                        }
                    }
                    if ( flag == 0 )
                        printf("NOT FOUND\n");
                }
                break;

            default:
                printf("INVALID INPUT\n");
                printf("%d remaining cars in parking\n",i);
                return 0;
        }
    }



    return 0;
}


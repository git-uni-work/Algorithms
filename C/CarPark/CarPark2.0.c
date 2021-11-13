#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "math.h"

typedef struct flor{

int full = 0;
int tim = 0;
char rz[11];

}flor;

int main() {

flor array[26][26];

char x,y;
int x1,y1;




printf("Dimensions:\n");
if(scanf("%c %c",&x,&y) != 2 || x<65 || x > 90 || y < 97 || y > 122 ){
  printf("Invalid input\n");
  return 0;
}
x1 = x - 64;
y1 = y - 96;
int remains = x1*y1;
char sign;
char str[11];
int max = 0;
int stop = 0;
int stop2 = 0;
int check;
printf("Requests:\n");

while(1){

stop = 0;
stop2 = 0;
check = scanf(" %c",&sign);
if(check == EOF)
return 0;
      if( (sign != '+' && sign != '-') ){

        printf("1 Invalid input\n");
        return 0;
      }

    if(sign == '+'){

                   scanf("%s",str);

                   if(remains == 0){
                   printf("Car park full\n");
                   max = 0;
                   continue;
                 }
                       for (int i = 0; i < x1; i++) {

                            for (int j = 0; j < y1; j++) {

                              if(array[i][j].tim >= max){
                              max = array[i][j].tim;

                              }
                           }
                      }

                     for (int i = 0; i < x1; i++) {
                       if(stop2 == 1)
                       break;
                          for (int j = 0; j < y1; j++) {
                            if(array[i][j].tim == max && array[i][j].full == 0){
                            strcpy(array[i][j].rz,str);
                            array[i][j].full = 1;
                            array[i][j].tim = 0;
                              remains --;
                              printf("Position: %c%c, remains: %d\n",i+65,j+97,remains);
                              stop2 = 1;
                              break;
                          }

                      }

                   }

          }

          if(sign == '-'){

             scanf(" %s",str);
            for (int i = 0; i < x1; i++) {
                 if(stop == 1)
                 break;
                 for (int j = 0; j < y1; j++) {

                   if(strcmp(array[i][j].rz , str) == 0){
                    array[i][j].full = 0;
                  //  array[i][j].tim = 0;
                    stop = 1;
                    remains ++;
                      printf("Position: %c%c, remains: %d\n",i+65,j+97,remains);
                    break;
                   }

                 }
            }
            if(stop == 0)
            printf("Not found\n");

          }

                         for (int i = 0; i < x1; i++) {

                              for (int j = 0; j < y1; j++) {

                                if(array[i][j].full == 0)
                                array[i][j].tim = array[i][j].tim + 1;
                              }
                         }

}

  return 0;
}

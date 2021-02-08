/* https://www.hackerrank.com/challenges/day-of-the-programmer/problem */
/* 2021-02-08 */

#include <stdio.h>

int main(){
    int year; 
    scanf("%d",&year);
    if(year<1918){
        if(year%4){
            printf("13.09.%4d\n",year);
        }
        else{
            printf("12.09.%4d\n",year);
        }
    }
    else if(year== 1918){
        printf("26.09.1918\n");
    }
    else{
        if((year%400 == 0) || (year%4 == 0 && year%100)){
            printf("12.09.%4d\n",year);
        }
        else{
            printf("13.09.%4d\n",year);
        }
    }
    return 0;
}

/* https://www.hackerrank.com/challenges/library-fine/problem */
/* 2021-02-17 */

#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<math.h>

int main() {

    int d1,d2,m1,m2,y1,y2;

    scanf("%d %d %d",&d1,&m1,&y1);
    scanf("%d %d %d",&d2,&m2,&y2);

    if((d1<d2) && (m1==m2) && (y1==y2))
        printf("0");

    else
        if((y1<y2))
            printf("0");
        else
            if((m1<m2) && (y1<=y2))
                printf("0");
            else
                if((d1==d2) && (m1==m2) && (y1==y2))
                    printf("0");
                else
                    if((d1>d2) && (m1==m2) && (y1==y2))
                        printf("%d",(15*(d1-d2)));
                    else
                        if((m1>m2) && (y1<=y2))
                            printf("%d",(500*(m1-m2)));
                        else
                            if((d1<d2) && (m1<m2) && (y1>y2))
                                printf("10000");
                            else if((d1!=d2) && (m1!=m2) &&(y1>y2))
                                printf("10000");
                            else 
                                printf("10000");   

    return 0;
}

/* https://www.hackerrank.com/challenges/sherlock-and-squares/problem */
/* 2021-02-18 */

#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<math.h>

int main() {

    int t;

    scanf("%d",&t);

    for(int i=1;i<=t;i++) {
        
        int a, b;
        int k=0, c=0;

        scanf("%d\n %d\n",&a,&b);

        for(int j=sqrt(a);j<=sqrt(b);j++) {  
            k=j*j;
            
            if(k>=a && k<=b)
                c++;
        }

        printf("%d\n",c);
    }

    return 0;
}

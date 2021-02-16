/* https://www.hackerrank.com/challenges/save-the-prisoner/problem */
/* 2021-02-16 */

#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<math.h>
#include<limits.h>

int main() {
    long long int t;
    long long int n,m,s;
    long long int p=0;
    
    scanf("%llu",&t);

    for(long long int i=1;i<=t;i++) {
        scanf("%llu %llu %llu",&n,&m,&s);
        p=(m+s-1)%n;

        if((m+s)<n)
            printf("%llu\n",(m+s-1));

        else {
            if((m+s)>n) {
                if(p==0)
                    printf("%llu\n",n);
                else
                    printf("%llu\n",(m+s-1)%n);
            }
        }
    }
    return 0;
    
}

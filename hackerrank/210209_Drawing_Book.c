/* https://www.hackerrank.com/challenges/drawing-book/problem */
/* 2021-02-09 */

#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>

int main(){
    int n; 
    scanf("%d",&n);
    int p; 
    scanf("%d",&p);
    int ans1,ans2;
    ans1=p/2;
    ans2=(n-p)/2;
    if(ans1>ans2)
     {
     printf("%d",ans2);
     }
    else
     {
        printf("%d",ans1);
    }
        
    return 0;
}

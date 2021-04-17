/* https://www.hackerrank.com/challenges/the-hurdle-race/problem */
/* 2021-04-17 */

#include<stdio.h>

int main()
{
    int n,k;
    scanf("%d%d",&n,&k);
    int height[n],max=0;
    for(int i=0;i<n;i++)
    {
        scanf("%d",&height[i]);
        if(max<height[i])
            max=height[i];
    }
    if(max-k > 0)
        printf("%d",max-k);
    else 
        printf("0");
}

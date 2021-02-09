/* https://www.hackerrank.com/challenges/electronics-shop/problem */
/* 2021-02-10 */

#include <stdio.h>

int main(){
    int b,usb[1000],key[1000],no=-1,i,j,n,m,result=0;
    scanf("%d %d %d",&b,&n,&m);

    for(i=0;i<n;i++){
        scanf("%d",&key[i]);
    }

    for(j=0;j<m;j++){
        scanf("%d",&usb[j]);
    }
    
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            result=key[i]+usb[j];
            if(result>no && result<=b){
                no=result;
            }
        }
    } 
    printf("%d",no);
}

/* https://www.hackerrank.com/challenges/acm-icpc-team/problem */
/* 2021-02-23 */

#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int main() {

    int n,m;
    scanf("%d %d",&n,&m);

    char* topic[n];

    for(int i=0;i<n;i++) {

        topic[i]=(char*)malloc(1024*sizeof(char));
        scanf("%s",topic[i]);
    }

    int high=-1;
    int bt=0;

    for(int i=0;i<n-1;i++) {

        for(int j=i+1;j<n;j++) {

            int know=0;
            for(int x=0;x<m;x++) {
               know+=(topic[i][x]=='1' || topic[j][x]=='1')?1:0;
            }

            if(know>high) {
                high=know;
                bt=1;
            }

            else
                if(know==high)
                    bt++;
        }
    }
    printf("%d\n%d\n",high,bt);
    
    return 0;
}

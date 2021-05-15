#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <math.h>

int main() {
    int n,k;
    scanf("%d %d", &n, &k);
    
    int np, sp, pn=0;
    for(int i=0; i<n; i++) {
        scanf("%d",&np);
        pn++;
        
        int problem=1;
        
        while(np>0) {
            np--;
            
            if(problem==pn)
                sp++;
                
            if(problem%k==0 && np!=0)
                pn++;
                
            problem++;
        }
    }
    
    printf("%d",sp);
    return 0;
}

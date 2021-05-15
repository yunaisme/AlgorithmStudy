#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <math.h>

int main() {
    int n;
    scanf("%d",&n);
    
    int a[n];
    for(int i=0; i<n; i++) {
        scanf("%d", &a[i]);
    }
    
    int c=0;
    
    for(int i=0; i<n-1; i++) {
        if(a[i]%2!=0) {
            a[i] = a[i]+1;
            a[i+1] = a[i+1]+1;
            c+=2;
        }
    }
    
    if(a[n-1]%2==0)
        printf("%d",c);
        
    else if(a[n-1]%2!=0)
        printf("NO");
        
    return 0;
}

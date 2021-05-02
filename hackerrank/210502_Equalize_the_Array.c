#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int main() {

    int n;
    scanf("%d",&n);

    int a[n];
    for(int i=0;i<n;i++) {
        scanf("%d",&a[i]);
    }

    int c=0;
    int p=0;

    for(int i=0;i<n;i++) {
        c=0;
        for(int j=0;j<n;j++) {
            if(a[i]==a[j])
                c++;
        }
        if(c>p)
            p=c;
    }

    printf("%d",(n-p));
    
    return 0;
}

/* https://www.hackerrank.com/challenges/halloween-sale/problem */
/* 2021-04-10 */

#include <stdio.h>

int main (void) {
    int p, d, m, s;
    int n, t;
    
    scanf("%d%d%d%d", &p, &d, &m, &s);
    int c = 0;
    
    while(1) {
        
        int price;
        
        if(p>m)
            price=p;
        else
            price=m;
            
        s = s-price;
        p = p-d;
        
        if(s>=0)
            c++;
        else
            break;
    }
    
    if(c < 0)
        printf("0");
        
    else
        printf("%d",c);
}

/* https://www.hackerrank.com/challenges/kaprekar-numbers/problem */
/* 2021-02-25 */

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {
    
    char *input = malloc(100);
    fgets(input, 10, stdin);
    long p = atoi(input) - 1;
    fgets(input, 10, stdin);
    long q = atoi(input);
    int count = 0;
    
    while (p++ < q) {
        long num = p*p;
        sprintf(input, "%ld", num);
        
        char tmp = input[strlen(input) / 2];
        int halflen = strlen(input) / 2;
        input[halflen] = '\0';
        long p1 = atoi(input);
       
        input[halflen] = tmp;
        input += halflen;
        long p2 = atoi(input);
        input -= halflen;
        if (p1 + p2 == p) {
            printf("%ld ", p);
            count++;
        }
    }
    
    if (count == 0)
        printf("INVALID RANGE");
    printf("\n");
    
    return 0;
}

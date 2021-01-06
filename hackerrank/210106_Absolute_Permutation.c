/* https://www.hackerrank.com/challenges/absolute-permutation/problem */
/* 2021-01-06 */

#include <assert.h>
#include <limits.h>
#include <math.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* readline();
char** split_string(char*);

// Complete the absolutePermutation function below.

/* Repeating computing absolute permutation, i find that there exists following laws
1. if n is odd number, absolute permutation exists when k = 0
2. if n/2 is smaller than k, there is no absolute permutation
3. if n is not divisible by k, there is no absolute permutation
4. if n/k is odd number, there is no absolute permutation
*/

int* absolutePermutation(int n, int k, int* result_count) {
    
    int* result = malloc(sizeof(int)*n);
    int *minus = malloc(sizeof(int));
    *minus = -1;
    int slice = 0;
    *result_count = n;
    
    /* if k is 0, there exists absolute permutation
    lexicographically smallest absolute permutation is same as p[i] */
    if (k==0) {
        for (int i=1; i<=n; i++){
            result[i-1] = i;
        }
        return result;
    }
    
    // check above laws
    if (n%2==1 || n/2<k || n%k!=0 || (n/k)%2==1){
        *result_count = 1;
        return minus;
    }
    
    // compute lexicographically smallest absolute permutation
    for (int i=0; i<n/(2*k); i++) {
        for (int j=0; j<k; j++) {
            result[slice+j] = j+slice+k+1;
            result[slice+j+k] = j+slice+1;
        }
        slice += (2*k);
    }
    return result;
    
}

int main()
{
    FILE* fptr = fopen(getenv("OUTPUT_PATH"), "w");

    char* t_endptr;
    char* t_str = readline();
    int t = strtol(t_str, &t_endptr, 10);

    if (t_endptr == t_str || *t_endptr != '\0') { exit(EXIT_FAILURE); }

    for (int t_itr = 0; t_itr < t; t_itr++) {
        char** nk = split_string(readline());

        char* n_endptr;
        char* n_str = nk[0];
        int n = strtol(n_str, &n_endptr, 10);

        if (n_endptr == n_str || *n_endptr != '\0') { exit(EXIT_FAILURE); }

        char* k_endptr;
        char* k_str = nk[1];
        int k = strtol(k_str, &k_endptr, 10);

        if (k_endptr == k_str || *k_endptr != '\0') { exit(EXIT_FAILURE); }

        int result_count;
        int* result = absolutePermutation(n, k, &result_count);

        for (int i = 0; i < result_count; i++) {
            fprintf(fptr, "%d", *(result + i));

            if (i != result_count - 1) {
                fprintf(fptr, " ");
            }
        }

        fprintf(fptr, "\n");
    }

    fclose(fptr);

    return 0;
}

char* readline() {
    size_t alloc_length = 1024;
    size_t data_length = 0;
    char* data = malloc(alloc_length);

    while (true) {
        char* cursor = data + data_length;
        char* line = fgets(cursor, alloc_length - data_length, stdin);

        if (!line) { break; }

        data_length += strlen(cursor);

        if (data_length < alloc_length - 1 || data[data_length - 1] == '\n') { break; }

        size_t new_length = alloc_length << 1;
        data = realloc(data, new_length);

        if (!data) { break; }

        alloc_length = new_length;
    }

    if (data[data_length - 1] == '\n') {
        data[data_length - 1] = '\0';
    }

    data = realloc(data, data_length);

    return data;
}

char** split_string(char* str) {
    char** splits = NULL;
    char* token = strtok(str, " ");

    int spaces = 0;

    while (token) {
        splits = realloc(splits, sizeof(char*) * ++spaces);
        if (!splits) {
            return splits;
        }

        splits[spaces - 1] = token;

        token = strtok(NULL, " ");
    }

    return splits;
}

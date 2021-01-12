/* https://www.hackerrank.com/challenges/bigger-is-greater/problem */
/* 2021-01-12 */

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

int static compare (const void* first, const void* second) {
    if (*(int*)first > *(int*)second)
        return 1;
    else if (*(int*)first < *(int*)second)
        return -1;
    else
        return 0;
}

// Complete the biggerIsGreater function below.
char* biggerIsGreater(char* w) {
    char* result = malloc(sizeof(char)*100);
    char lastIndex = strlen(w)-1;
    char changedIndex;
    char temp;
    int flag = 0;
    
    while(lastIndex>0 && strlen(w)!=1){
        for(int i=lastIndex; i>-1; i--){
            if(w[i] < w[lastIndex]){
                changedIndex = i;
                temp = w[lastIndex];
                w[lastIndex] = w[i];
                w[i] = temp;
                flag = 1;
                break;
            }
        }
        if(flag==1) break;
        lastIndex--;
    }
    
    if(flag==0) result = "no answer";
    else {
        qsort(&w[changedIndex+1],(strlen(w)-1)-changedIndex,sizeof(char),compare);
        result = w;
    }
    
    return result;
}

int main()
{
    FILE* fptr = fopen(getenv("OUTPUT_PATH"), "w");

    char* T_endptr;
    char* T_str = readline();
    int T = strtol(T_str, &T_endptr, 10);

    if (T_endptr == T_str || *T_endptr != '\0') { exit(EXIT_FAILURE); }

    for (int T_itr = 0; T_itr < T; T_itr++) {
        char* w = readline();

        char* result = biggerIsGreater(w);

        fprintf(fptr, "%s\n", result);
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

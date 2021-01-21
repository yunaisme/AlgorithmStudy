/* https://www.hackerrank.com/challenges/time-conversion/problem */
/* 2021-01-21 */

#include <assert.h>
#include <limits.h>
#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* readline();

char* timeConversion(char* s) {
    
    char* result = s;
    char t[3] = {s[8],s[9],'\0'};
    char h[3] = {s[0],s[1],'\0'};
    
    result[8] = '\0';
    
    if(strcmp(t,"PM")==0 && strcmp(h,"12")!=0){
            result[0]=result[0]+1;
            result[1]+=2;
    }
    else if(strcmp(t,"AM")==0 && strcmp(h,"12")==0){
        result[0]=48;
        result[1]=48;
    }
    
    return result;
}

int main()
{
    FILE* fptr = fopen(getenv("OUTPUT_PATH"), "w");

    char* s = readline();

    char* result = timeConversion(s);

    fprintf(fptr, "%s\n", result);

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

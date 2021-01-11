/* https://www.hackerrank.com/challenges/the-time-in-words/problem */
/* 2021-01-11 */

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

// Complete the timeInWords function below.
char* timeInWords(int h, int m) {
    
    char *result = malloc(sizeof(char)*40);
    char *numberInWords[] = {
        "one","two","three","four","five","six","seven","eight","nine","ten","eleven",
        "twelve","thirteen","fourteen","fiveteen","sixteen","seventeen","eighteen",
        "nineteen","twenty","twenty one","twenty two","twenty three","twenty four",
        "twenty five","twenty six","twenty seven","twenty eight","twenty nine"
    };
    
    if(m == 0) {
        strcpy(result,numberInWords[h-1]);
        strcat(result," o' clock");
    }
    else if (m <= 30) {
        if(m==1) {
            strcpy(result,numberInWords[m-1]);
            strcat(result," minute past ");
            strcat(result,numberInWords[h-1]);
        }    
        if(m==15) {
            strcpy(result,"quarter past ");
            strcat(result,numberInWords[h-1]);
        }
        if(m==30) {
            strcpy(result,"half past ");
            strcat(result,numberInWords[h-1]);
        }
        else if(m!=1 && m!=15 && m!=30) {
            strcpy(result, numberInWords[m-1]);
            strcat(result, " minutes past ");
            strcat(result, numberInWords[h-1]);
        }
    }
    else if (m > 30) {
        if(m==45) {
            strcpy(result,"quarter to ");
            strcat(result, numberInWords[h]);
        }    
        if(m==59) {
            strcpy(result, numberInWords[m-1]);
            strcat(result, " minutes to ");
            strcat(result, numberInWords[h]);
        }
        else if(m!=45 && m!=59) {
            strcpy(result, numberInWords[60-m-1]);
            strcat(result, " minutes to ");
            strcat(result, numberInWords[h]);
        }
    }
    
    return result;
}

int main()
{
    FILE* fptr = fopen(getenv("OUTPUT_PATH"), "w");

    char* h_endptr;
    char* h_str = readline();
    int h = strtol(h_str, &h_endptr, 10);

    if (h_endptr == h_str || *h_endptr != '\0') { exit(EXIT_FAILURE); }

    char* m_endptr;
    char* m_str = readline();
    int m = strtol(m_str, &m_endptr, 10);

    if (m_endptr == m_str || *m_endptr != '\0') { exit(EXIT_FAILURE); }

    char* result = timeInWords(h, m);

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

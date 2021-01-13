/* https://www.hackerrank.com/challenges/encryption/problem */
/* 2021-01-13 */

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

// Complete the encryption function below.
char* encryption(char* s) {
    
    char* plainText = s;
    char* plainTextWithoutSpace;
    char* cyperText = malloc(100*sizeof(char));
    int size = strlen(plainText);
    int p=0;
    int k=0;
    
    for (int i=0; plainText[i]!='\0'; i++){
        if(plainText[i] == ' ')
            size--;
    }

    plainTextWithoutSpace = malloc(size*sizeof(char));
    
    //delete space
    for (int j=0; plainText[j]!='\0'; j++){
        if (plainText[j]!=' '&&p<size){
            plainTextWithoutSpace[p] = plainText[j];
            p++;
        }
    }
    
    float root = sqrt(size);
    int rows = floor(root);
    int columns = ceil(root);
    
    if(rows*columns<size) rows++;    
    
    while(true){
        for (int i=0; i<columns; i++){
            int j=i;
            while(j<size){
                cyperText[k] = plainTextWithoutSpace[j];
                j += columns;
                k++;
            }
            cyperText[k]=' ';
            k++;
        }
        break;   
    }
    
    return cyperText;
}

int main()
{
    FILE* fptr = fopen(getenv("OUTPUT_PATH"), "w");

    char* s = readline();

    char* result = encryption(s);

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

/* https://www.hackerrank.com/challenges/magic-square-forming/problem */
/* 2021-01-04 */

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

// Complete the formingMagicSquare function below.
int formingMagicSquare(int s_rows, int s_columns, int** s) {
    
    /*it is hard to transform array s to magic square,
    so let's compute all costs of all possible magic square.
    this solution is easier, because number of 3x3 magic square is small enough.*/
    
    /*magic square can be computed easily using linear algebra*/
    
    int magic0[3][3] = {{2,9,4}, {7,5,3}, {6,1,8}};
    int magic1[3][3] = {{2,7,6}, {9,5,1}, {4,3,8}};
    int magic2[3][3] = {{4,9,2}, {3,5,7}, {8,1,6}};
    int magic3[3][3] = {{4,3,8}, {9,5,1}, {2,7,6}};
    int magic4[3][3] = {{6,7,2}, {1,5,9}, {8,3,4}};
    int magic5[3][3] = {{6,1,8}, {7,5,3}, {2,9,4}};
    int magic6[3][3] = {{8,3,4}, {1,5,9}, {6,7,2}};
    int magic7[3][3] = {{8,1,6}, {3,5,7}, {4,9,2}};

    int cost[8] = {};
    int min_cost;
    
    for (int i=0; i<3; i++){
        for (int j=0; j<3; j++){
            cost[0] += abs(s[i][j] - magic0[i][j]);
            cost[1] += abs(s[i][j] - magic1[i][j]);
            cost[2] += abs(s[i][j] - magic2[i][j]);
            cost[3] += abs(s[i][j] - magic3[i][j]);
            cost[4] += abs(s[i][j] - magic4[i][j]);
            cost[5] += abs(s[i][j] - magic5[i][j]);
            cost[6] += abs(s[i][j] - magic6[i][j]);
            cost[7] += abs(s[i][j] - magic7[i][j]);
        }
    }
    
    min_cost = cost[0];
    for (int k=0; k<8; k++){
        if(min_cost > cost[k]) min_cost = cost[k];
    }
    
    return min_cost;
    
}

int main()
{
    FILE* fptr = fopen(getenv("OUTPUT_PATH"), "w");

    int** s = malloc(3 * sizeof(int*));

    for (int i = 0; i < 3; i++) {
        *(s + i) = malloc(3 * (sizeof(int)));

        char** s_item_temp = split_string(readline());

        for (int j = 0; j < 3; j++) {
            char* s_item_endptr;
            char* s_item_str = *(s_item_temp + j);
            int s_item = strtol(s_item_str, &s_item_endptr, 10);

            if (s_item_endptr == s_item_str || *s_item_endptr != '\0') { exit(EXIT_FAILURE); }

            *(*(s + i) + j) = s_item;
        }
    }

    int s_rows = 3;
    int s_columns = 3;

    int result = formingMagicSquare(s_rows, s_columns, s);

    fprintf(fptr, "%d\n", result);

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

        if (!line) {
            break;
        }

        data_length += strlen(cursor);

        if (data_length < alloc_length - 1 || data[data_length - 1] == '\n') {
            break;
        }

        alloc_length <<= 1;

        data = realloc(data, alloc_length);

        if (!line) {
            break;
        }
    }

    if (data[data_length - 1] == '\n') {
        data[data_length - 1] = '\0';

        data = realloc(data, data_length);
    } else {
        data = realloc(data, data_length + 1);

        data[data_length] = '\0';
    }

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

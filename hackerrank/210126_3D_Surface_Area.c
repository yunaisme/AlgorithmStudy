/* https://www.hackerrank.com/challenges/3d-surface-area/problem */
/* 2021-01-26 */

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

// Complete the surfaceArea function below.
int surfaceArea(int A_rows, int A_columns, int** A) {
    int result=0;
    int maxSumOfOneRow=0;
    int maxSumOfOneColumn=0;
    
    int dirX[4] = {-1, 1, 0, 0};
    int dirY[4] = {0, 0, -1, 1};
    
    //surfaceArea of top and bottom
    result += A_rows*A_columns*2;
    
    //surfaceArea of side
    for(int x=0; x<A_rows; x++) {
            for(int y=0; y<A_columns; y++) {
                
                //주위에 있는 좌,우,앞,뒤 블럭들과 비교
                for(int d=0; d<4; d++) {
                    int cx = x + dirX[d];
                    int cy = y + dirY[d];
                     
                    if(cx < 0 || cx >= A_rows || cy < 0 || cy >= A_columns) {
                        result += A[x][y];
                    }
                    else { 
                        // 현재 큐브가 비교되는 큐브보다 높다면 그 차이만큼 축적
                        // 큐브 높이가 낮은 경우에는 해당 면이 덮여있으므로 skip
                        if(A[x][y] > A[cx][cy]) {
                            result += abs(A[x][y]-A[cx][cy]);
                        }
                    }
                }
            }
        }

    return result;
}

int main()
{
    FILE* fptr = fopen(getenv("OUTPUT_PATH"), "w");

    char** HW = split_string(readline());

    char* H_endptr;
    char* H_str = HW[0];
    int H = strtol(H_str, &H_endptr, 10);

    if (H_endptr == H_str || *H_endptr != '\0') { exit(EXIT_FAILURE); }

    char* W_endptr;
    char* W_str = HW[1];
    int W = strtol(W_str, &W_endptr, 10);

    if (W_endptr == W_str || *W_endptr != '\0') { exit(EXIT_FAILURE); }

    int** A = malloc(H * sizeof(int*));

    for (int i = 0; i < H; i++) {
        *(A + i) = malloc(W * (sizeof(int)));

        char** A_item_temp = split_string(readline());

        for (int j = 0; j < W; j++) {
            char* A_item_endptr;
            char* A_item_str = *(A_item_temp + j);
            int A_item = strtol(A_item_str, &A_item_endptr, 10);

            if (A_item_endptr == A_item_str || *A_item_endptr != '\0') { exit(EXIT_FAILURE); }

            *(*(A + i) + j) = A_item;
        }
    }

    int A_rows = H;
    int A_columns = W;

    int result = surfaceArea(A_rows, A_columns, A);

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

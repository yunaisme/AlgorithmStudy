/* https://www.hackerrank.com/challenges/organizing-containers-of-balls/problem */
/* 2021-01-05 */

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

// Complete the organizingContainers function below.

/* it is easy to show that it is always 'possible' if each container's capacity(number of balls that already exist) is equal to each number of balls of different types. */
char* organizingContainers(int container_rows, int container_columns, int** container) {

    int * containerCapacity = malloc(sizeof(int)*container_rows);
    int * totalNumOfEachBallType = malloc(sizeof(int)*container_columns);
    int flag = 0;
    
    // initialize arrays
    for (int i=0; i<container_rows; i++){
        containerCapacity[i] = 0;
    }
    for (int j=0; j<container_columns; j++){
        totalNumOfEachBallType[j] = 0;
    }

    // compute containerCapacity
    for (int i=0; i<container_rows; i++){
        for (int j=0; j<container_columns; j++){
            containerCapacity[i] += container[i][j];
        }
    }
    
    // compute totalNumOfEachBallType
    for (int j=0; j<container_columns; j++){
        for (int i=0; i<container_rows; i++){
            totalNumOfEachBallType[j] += container[i][j];
        }
    }
    
    // check whether it is possible or not
    for (int j=0; j<container_columns; j++){
        for (int i=0; i<container_rows; i++){
            if(totalNumOfEachBallType[j] == containerCapacity[i]) {
                flag = 1;
                break;
            }
            else flag = 0;
        }
        if (flag == 0) return "Impossible";
    }
    return "Possible";
}

int main()
{
    FILE* fptr = fopen(getenv("OUTPUT_PATH"), "w");

    char* q_endptr;
    char* q_str = readline();
    int q = strtol(q_str, &q_endptr, 10);

    if (q_endptr == q_str || *q_endptr != '\0') { exit(EXIT_FAILURE); }

    for (int q_itr = 0; q_itr < q; q_itr++) {
        char* n_endptr;
        char* n_str = readline();
        int n = strtol(n_str, &n_endptr, 10);

        if (n_endptr == n_str || *n_endptr != '\0') { exit(EXIT_FAILURE); }

        int** container = malloc(n * sizeof(int*));

        for (int i = 0; i < n; i++) {
            *(container + i) = malloc(n * (sizeof(int)));

            char** container_item_temp = split_string(readline());

            for (int j = 0; j < n; j++) {
                char* container_item_endptr;
                char* container_item_str = *(container_item_temp + j);
                int container_item = strtol(container_item_str, &container_item_endptr, 10);

                if (container_item_endptr == container_item_str || *container_item_endptr != '\0') { exit(EXIT_FAILURE); }

                *(*(container + i) + j) = container_item;
            }
        }

        int container_rows = n;
        int container_columns = n;

        char* result = organizingContainers(container_rows, container_columns, container);

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

#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>

int main(){
    int n; 
    scanf("%d",&n);
    
    int *score = malloc(sizeof(int) * n);
    for(int score_i = 0; score_i < n; score_i++) {
       scanf("%d",&score[score_i]);
    }
    
    int maxScoreAns = 0, minScoreAns = 0, maxScore = score[0], minScore = score[0];
    for(int i = 1; i < n; i++) {
       if(score[i] > maxScore) {
            maxScore = score[i];
            maxScoreAns++;
       }
       
       if(score[i] < minScore) {
        minScore = score[i];
        minScoreAns++;
       }
    }
    
    printf("%d %d\n", maxScoreAns, minScoreAns);
    return 0;
}

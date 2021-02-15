/* https://www.hackerrank.com/challenges/append-and-delete/problem */
/* 2021-02-15 */

#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <climits>
#include <deque>
#include <iostream>
#include <list>
#include <limits>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <vector>

#define ll long long

#define MIN(a, b) a < b ? a : b
#define MAX(a, b) a > b ? a : b

using namespace std;

int readline(char *str) {
    int i = 0;
    char ch;
    while((ch = getchar()) != '\n') {
        str[i++] = ch;
    }
    str[i] = '\0';
    return i;
}

int main(int argc, char *argv[]) {
    char *s = (char *) malloc(110 * sizeof(char));
    char *t = (char *) malloc(110 * sizeof(char));
    int chances;

    int ls = readline(s);
    int lt = readline(t);
    scanf("%d", &chances);

    int i = 0;
    while(s[i] && t[i]) {
        if(s[i] != t[i]) {
            break;
        }
        i++;
    }
    int prefix_length = i;
    int is_possible;

    if(chances >= (lt + ls)) {
        printf("Yes\n");
        return 0;
    }

    chances -= abs(lt - prefix_length);
    chances -= abs(ls - prefix_length);

    if(chances < 0) {
        printf("No\n");
        return 0;
    }

    if(chances % 2 == 0) {
        printf("Yes\n");
        return 0;
    }

    printf("No\n");
    return 0;
}

/* https://www.acmicpc.net/problem/14501 */
/* 2021-01-23 */

/*
N이 최대 15라 전체 경우의 수가 충분히 작다고 판단하여 그냥 dfs를 통해 가능한 모든 경우의 수를 따져야 겠다고 생각했다.
(또 보통 DP로 푸는 것 같은데 점화식을 어떻게 세울지 잘 모르겠음)
*/

#include<iostream>
#include<algorithm>
using namespace std;

int t[15], p[15]; //그 날에 할 수 있는 상담의 소요 시간과 이익, 최대 15일동안 상담할 수 있다(날짜는 0부터 센다)
int n, maxPrice; //상담할 수 있는 일 수(N), 즉 퇴사 날짜와 최대 이익

void dfs(int i, int totalPrice) {
//i: 현재 날짜, totalPrice: 현재까지의 이익

//재귀의 탈출 조건 -> 오늘이 퇴사 날인가? 즉 i==n?
    if (i==n) {
        maxPrice = max(maxPrice, totalPrice);
        return;
    }

/*
어떤 날 i에 대하여, 가능한 경우는 상담을 하느냐/마느냐 뿐이다.
상담을 할 경우에는 다음 상담을 할 날짜와 현재 이익에 상담 금액을 더해 파라미터를 전달하고,
상담을 하지 않을 경우에는 다음날 날짜와 현재 이익을 파라미터로 전달한다.
*/

//상담을 한다면, i+t[i]가 퇴사 날짜보다 이전이여야 한다
    if (i+t[i]<=n) {
        dfs(i+t[i], totalPrice+p[i]);
    }

//상담을 하지 않는다면, 다음날인 i+1번째 날이 퇴사 날짜보다 이전이여야 한다
        if (i+1<=n) {
        dfs(i+1, totalPrice);
    }
}

int main() {
	
//N, T, P 입력 받음
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> t[i];
        cin >> p[i];
    }

//dfs로 전체 경우 탐색
    dfs(0, 0);

//결과 출력
    cout << maxPrice << endl;
    return 0;
}

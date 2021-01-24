/* https://www.acmicpc.net/problem/15684 */
/* 2021-01-23 */


/*
추가해야 하는 가로선 개수의 최솟값을 출력하면 되는 것이다.
이때 만약 3보다 크다면 불가능한 경우와 마찬가지로 -1을 출력하면 되므로,
단순히 모든 위치에 가로선을 하나, 둘, 세개씩 놓아보며 최솟값을 갱신해보는 식으로 문제를 풀면 된다.

가로선을 놓으면서 주의할 것은, 가로선이 겹치거나 연결되면 안된다는 것이다. 이것만 주의해서 모든 위치에 가로선을 놓으면 된다.

세로선들의 연결 상태를 표현하기 위해 isVisited라는 2차원 배열을 사용했다.
isVisited[b][a] = true는, b와 b+1번 세로선이 a번 가로선에 의해 연결되어 있다는 의미인데, 
조건에 의해 이는 b-1와 b번 세로선, b번과 b+1번 세로선은 a번 가로선에 의해 연결될 수 없음을 내포한다.
*/

#include<iostream>
#include<algorithm>

using namespace std;
 
int N, M, H, Answer=99999999;
bool isVisited[11][31];

//사다리 조작에 성공했는지 판단하는 함수, 성공했다면 true 반환
bool Ladder_Game() {
    for (int i = 1; i <= N; i++) {
        int Current_Num = i;
        for (int j = 1; j <= H; j++) {
            if (isVisited[Current_Num][j] == true) Current_Num = Current_Num + 1;
            else if (isVisited[Current_Num-1][j] == true) Current_Num = Current_Num - 1;
        }
 
        if (Current_Num != i) return false;
    }
    return true;
}
 
void Select_Line(int Idx, int Cnt) {
//Cnt: 추가된 가로선의 갯수

//추가된 가로선의 갯수가 3개가 넘는다면 -1 출력
    if (Cnt >= 4) return;
    
//사다리 조작에 성공했다면 가로선의 갯수를 최솟값으로 갱신
    if (Ladder_Game() == true) {
        Answer = min(Answer, Cnt);
        return;
    }
 
/*
사다리 조작에 실패했으므로 가로선을 하나 더 추가한다.
for문을 통해 가로선을 추가할 수 있는 위치를 찾는 것
*/
    for (int i = Idx; i <= H; i++) {
        for (int j = 1; j < N; j++) {

//가로선이 겹치거나 연결되면 안된다는 조건을 고려한다
            if (isVisited[j][i] == true) continue;
            if (isVisited[j - 1][i] == true) continue;
            if (isVisited[j + 1][i] == true) continue;

//가로선의 갯수를 하나 더 추가한다
            isVisited[j][i] = true;
            Select_Line(i, Cnt + 1);

//고려된 경우는 다시 원상복귀
            isVisited[j][i] = false;
        }
    }
}
                            
int main(void) {

//사다리 상태 입력받음   
    cin >> N >> M >> H;
    for (int i = 0; i < M; i++)
    {
        int a, b;
        cin >> a >> b;
        isVisited[b][a] = true;

    Select_Line(1, 0);    

//답을 찾지 못한 경우
    if (Answer == 99999999) Answer = -1;

//결과 출력
    cout << Answer << '\n';
 
    return 0;
}

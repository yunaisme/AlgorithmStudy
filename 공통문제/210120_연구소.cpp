/* https://www.acmicpc.net/problem/14502 */
/* 2021-01-20 */

/*
안전 영역 크기의 최댓값을 구하는 문제이고, 또 연구소 크기가 최대 8x8, 세울 수 있는 벽의 개수도 3으로 제한되어 있으므로 
벽을 세우는 모든 경우에 대해 바이러스를 퍼뜨려보고 안전 영역 크기를 계산하여 그 중 최댓값을 구하면 되겠다
벽을 세우는 모든 경우를 다 고려할 때까지 다음을 반복하자:
가상의 연구소에 3개의 벽을 세운다
-> 가상의 연구소에 바이러스를 퍼뜨린다
-> 안전 영역의 크기를 계산한다
-> 기존의 안전 영역 크기와 비교하여 최대인지 확인한다
*/

#include <cstdio>
#include <algorithm>
#include <queue>
 
using namespace std;
 
int lab[8][8]; //실제 연구실 상황
int tempLab[8][8]; //가상의 연구실
int n,m; //연구실 크기
int maxSafeArea = 0;
 
//가상의 연구실에 연구실 상황을 복사하는 함수
void labCopy(int (*a)[8], int (*b)[8]){
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            a[i][j] = b[i][j];
        }
    }
}

void virusSpread(){
    int tempSpreadLab[8][8]; //바이러스를 퍼뜨린 가상의 연구실
    labCopy(tempSpreadLab, tempLab);
    
    //큐에 바이러스가 있는 영역을 모두 넣음
    queue<pair<int, int>> q;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (tempSpreadLab[i][j] == 2)
                q.push(make_pair(i, j));
    
    //바이러스 주변공간의 좌표 계산을 위함(위, 아래, 왼쪽, 오른쪽)
    int dx[] = {0,0,-1,1};
    int dy[] = {-1,1,0,0};
    
    //큐에서 바이러스 영역들을 하나씩 꺼내 주변 공간을 감염시킴
    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        
        //바이러스 주변 영역들이 연구실 내 영역일 경우 감염시킴
        for(int i = 0; i < 4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(0<=nx && nx<n && 0<=ny && ny<m){
                if(tempSpreadLab[nx][ny] == 0){
                    tempSpreadLab[nx][ny] = 2;
                    q.push(make_pair(nx, ny));
                }
            }
        }
    }
    
    //안전 영역의 크기 계산
    int tempSafeArea = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(tempSpreadLab[i][j] == 0)
                tempSafeArea+=1;
        }
    }
    maxSafeArea = max(maxSafeArea, tempSafeArea);
}
 
//벽 세우기
void wall(int num){
    
    //벽을 다 세웠다면 바이러스를 퍼뜨림
    if(num == 3){
        virusSpread();
        return;
    }
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if(tempLab[i][j]==0){
                //비어있는 곳을 찾아 벽을 세움
                tempLab[i][j] = 1;
                wall(num+1);
                
                //모든 경우를 고려하기 위해 다시 0으로 바꿔줌
                tempLab[i][j] = 0;
            }
        }
    }
}
 
int main(){
    
    //연구실 상황 입력받기
    scanf("%d %d",&n,&m);
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            scanf("%d", &lab[i][j]);
        }
    }
    
    //벽을 세울 수 있는 모든 경우를 고려
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if(lab[i][j] == 0){
                labCopy(tempLab,lab);
                tempLab[i][j] =1;
                wall(1);
                tempLab[i][j] = 0;
            }
        }
    }
    
    //결과 출력
    printf("%d\n",maxSafeArea);
    return 0;
}

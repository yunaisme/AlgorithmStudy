/* https://www.acmicpc.net/problem/14503 */
/* 2021-01-29 */

#include<iostream> 
using namespace std; 

#define MAX 51 

int N, M; //장소 크기
int input[MAX][MAX]; //장소 정보
int x, y, direction; //청소기의 위치와 방향 
int result; //청소하는 칸의 개수

//북, 동, 남, 서 
int dx[] = { -1, 0, 1, 0 }; 
int dy[] = { 0, 1, 0, -1 }; 

int main() { 
  //장소 입력 받음
  cin >> N >> M; 
  cin >> x >> y >> direction; 
  
  for (int i = 0; i < N; i++) 
    for (int j = 0; j < M; j++) 
      cin >> input[i][j]; 
  
  /*
  탈출 조건: 네 방향 모두 청소가 이미 되어있거나 벽이면서, 
  뒤쪽 방향이 벽이라 후진도 할 수 없는 경우 작동을 멈춘다(2-d)
  */
  while (1) { 
    
    //현재위치를 청소한다(단계 1)
    if (input[x][y] == 0) { 
      input[x][y] = 2; 
      result++; 
    } 
    
    //청소할 공간을 탐색한다
    int nextStep = 0; 
    for (int i = 0; i < 4; i++) {
      //왼쪽 방향으로 전환 
      direction = (direction + 3) % 4; 
      int newX = x + dx[direction]; 
      int newY = y + dy[direction]; 
      
      //청소할 공간을 찾았다면 그 곳으로 전진
      if (input[newX][newY] == 0) { //청소하지 않은 공간 존재
        x = newX; 
        y = newY; 
        nextStep = 1; 
        break; 
      } 
    } 
    
    //청소할 공간을 찾았으므로 다시 2번으로 돌아감
    if (nextStep == 1) 
      continue; 
    
    //청소할 공간을 찾지 못했으므로 바라보는 방향을 유지한 채로 한 칸 후진(2-c)
    int newDirection = (direction + 2) % 4; 
    x = x + dx[newDirection]; 
    y = y + dy[newDirection]; 
    
    //뒤쪽 방향이 벽이라 후진도 할 수 없어 작동을 중지(2-d)
    if (input[x][y] == 1) 
      break; 
  
  } 
  cout << result; 
}

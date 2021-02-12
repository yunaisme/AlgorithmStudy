/* https://www.acmicpc.net/problem/2583 */
/* 2021-02-12 */

#include<iostream>
#include<queue>
#include<cstdio>
#include<algorithm>
using namespace std;

int N , M , K;
int map[101][101];
int visited[101][101];
int ans[101];
int vety[] = {1 , 0, -1, 0};
int vetx[] = {0 , -1 ,0 ,1};
int cnt = 0 ;
 
queue<pair<int ,int> > q ;
 
void BFS()
{
    int i , curx  ,cury; 
    
    while(!q.empty()) {    
            curx = q.front().second;
            cury = q.front().first;
            q.pop();
 
            for(i = 0  ; i < 4 ; i++) {
                int nextx = curx + vetx[i];
                int nexty = cury + vety[i];
 
                if(nextx >= 0 && nextx < M && nexty >= 0 && nexty < N) {
                    if(!map[nexty][nextx] && !visited[nexty][nextx]) {
                        q.push({ nexty , nextx });
                        visited[nexty][nextx] = 1 ;
                        ans[cnt]++;
                    }
                }
            }
    }
}
 
 
int main()
{
    int i,j;
    cin >>  N >> M  >> K;
 
    while(K--) {
        int y1,x1,y2,x2;
        cin >> x1 >> y1  >> x2 >>y2;
        
        for(i=y1; i<y2 ; i++)
            for(j=x1 ; j<x2; j++ )
                map[i][j] =1;        
    }
    
 
    for(i=0; i<N ; i++)
         for(j=0 ; j<M ; j++ )
             if( !map[i][j]  && !visited[i][j]) {
                visited[i][j] = 1;
                ans[cnt] = 1;
                q.push({i,j});
                BFS();
                cnt++;
          }
        
    sort(ans ,ans + cnt );
    
    cout << cnt << "\n";
    for(i= 0; i < cnt ;i++)
        cout << ans[i] << " "; 
}

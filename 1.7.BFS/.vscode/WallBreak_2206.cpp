#include <bits/stdc++.h>
using namespace std;
#define X get<0> (cur)
#define Y get<1> (cur)
#define ONE get<2> (cur)
#define MAX 1001
string board[MAX];
int dist[MAX][MAX];
int dist2[MAX][MAX];
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};
int hasone;
int n,m;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    queue<tuple<int,int,int>> Q;
    cin >> n >> m;
    for(int i = 0; i < n;i++){
        fill(dist[i],dist[i] + m,-1);
        fill(dist2[i],dist2[i]+ m,-1);
    } 
    for(int i = 0 ; i<n;i++) cin >> board[i];
    dist[0][0] = 1;
    Q.push({0,0,1});
    if(n == 1 && m == 1){
        cout << 1<<'\n';
        return 0;
    }
    while(!Q.empty()){
        tuple<int,int,int> cur = Q.front();Q.pop();
        for(int dir=0;dir < 4;dir++)
        {
            int nx = X + dx[dir];
            int ny = Y + dy[dir];
            hasone = ONE;

            if(nx<0||nx>=n||ny<0||ny>=m) continue;
            // if(dist[nx][ny] >=0 || dist2[nx][ny] >= 0) continue;
            // 이렇게 조건식 짜면 안되는 이유 -> dist[nx][ny] == -1 일때 dist2[nx][ny] >=0 일 수 있음 
            // 이미 벽을 깨서 구한 값이 있는데 저렇게 조건식을 쓰면 벽을 깨지않고 갈길이 있는데 dist2[nx][ny] >=0 이면 탈출해버리니까 원하는 결과를 못가져온다 
            if(dist[nx][ny] >=0) continue;
            // 기본적인 BFS했을때의 경우는 변하지 않으므로 기본틀을 만들고 
            if(board[nx][ny] == '1'){
                if(hasone == 1 && dist2[nx][ny] == -1){ // 아직 벽깨고 간 적 없지? 묻는거(BFS니까 먼저 벽깨고 간 경우가 젤 빠를거임)
                    dist2[nx][ny] = dist[X][Y] + 1;
                    Q.push({nx,ny,0});
                }
            }
            else if(board[nx][ny] == '0'){
                if(hasone == 0 && dist2[nx][ny] == -1){
                    dist2[nx][ny] = dist2[X][Y] + 1;
                    Q.push({nx,ny,hasone});
                }else if(hasone ==1){
                    dist[nx][ny] = dist[X][Y] + 1;
                    Q.push({nx,ny,hasone});
                }
            }
            if(nx == n-1 && ny == m-1){
                if(dist2[n-1][m-1]!= -1) cout << dist2[nx][ny]<<'\n';
                else cout << dist[nx][ny] <<'\n';
                return 0;
            }
        }
    }
    cout << -1 <<'\n';
    // for(int i = 0; i < n;i++)
    // {
    //     for(int j = 0 ; j < m;j++){
    //         cout << dist2[i][j] << ' ';
    //     }
    //     cout << '\n';
    // }
}   


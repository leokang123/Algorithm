#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second 
#define MAX 1002
int board[MAX][MAX];
int time1;
int dis[MAX][MAX];
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m; cin >> m >> n;
    queue<pair<int, int>> Q;

    for(int i = 0;i < n;i++) fill(dis[i],dis[i]+m,-1); // fill 쓸때는 그냥 열 갯수만큼 더해주면 됌 
    for(int i = 0; i < n;i++){
        for(int j = 0;j < m;j++){
            cin >> board[i][j];
            if(board[i][j] == 1){
                dis[i][j]++;
                Q.push({i,j});
            }
        }
    }
    while(!Q.empty())
    {
        pair<int, int> cur = Q.front();Q.pop();
        for(int dir = 0;dir < 4;dir++){
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];
            if(nx<0||nx>=n||ny<0||ny>=m) continue;
            if(dis[nx][ny] >= 0 || board[nx][ny] == -1) continue;
            dis[nx][ny] = dis[cur.X][cur.Y] + 1;
            time1 = max(time1,dis[nx][ny]);
            Q.push({nx,ny});
        }
    }
    for(int i = 0;i<n;i++){
        for(int j=0;j<m;j++){
            if(dis[i][j] == -1 && board[i][j] == 0){
                cout << -1 <<'\n';
                return 0;
            }
        }
    }
    cout << time1 << '\n';
}
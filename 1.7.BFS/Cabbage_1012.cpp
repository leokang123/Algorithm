#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second
#define MAX 52
int board[MAX][MAX];
bool vis[MAX][MAX];
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};
int T,n,m,K;
int time1;
int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int a,b;
    cin >> T;
    while(T--){
        time1 = 0;
        cin >> n >> m >> K;
        queue<pair<int, int>> Q;
        for(int l = 0;l < n;l++){ // 반복마다 초기화 시켜줘야 함 
            fill(board[l],board[l] + m,0);
            fill(vis[l],vis[l] + m,0);
        }
        for(int l = 0;l < K;l++)
        {
            cin >> a >> b;
            board[a][b] = 1;
        }
        for(int i = 0;i<n;i++){ 
            for(int j = 0;j<m;j++){
                if(vis[i][j] != 0 || board[i][j] != 1) continue;
                time1++;
                vis[i][j] = 1;
                Q.push({i,j});
                while(!Q.empty())
                {
                    pair<int, int> cur = Q.front(); Q.pop();
                    for(int dir = 0; dir < 4; dir++){
                        int nx = cur.X + dx[dir];
                        int ny = cur.Y + dy[dir];
                        if(nx<0||nx>=n||ny<0||ny>=m) continue;
                        if(vis[nx][ny] != 0 || board[nx][ny] != 1) continue;  
                        vis[nx][ny] = 1;
                        Q.push({nx,ny});
                    }
                }
            }
        }
        cout << time1 << '\n';
    }
}
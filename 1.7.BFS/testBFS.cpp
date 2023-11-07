#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second
int board[502][502];
bool vis[502][502];
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};
int n,m;
int main(void)
{
    cin >> n >> m;
    queue<pair<int, int>> Q;
    for(int i = 0;i<n;i++){
        for(int j = 0;j<m;j++){
            cin >> board[i][j];
        }
    }
    vis[0][0] = 1;
    Q.push({0,0});
    for(int i = 0;i<n;i++){
        for(int j = 0;j<m;j++){
            if(vis[i][j] != 0 || board[i][j] != 1) continue;
                vis[i][j] = 1;
                Q.push({i,j});
                cout<<"Next one: ";
            while(!Q.empty())
            {
                pair<int, int> cur = Q.front(); Q.pop();
                cout << "(" << cur.X << "," << cur.Y <<  ") -> ";
                for(int dir = 0; dir < 4; dir++){
                    int nx = cur.X + dx[dir];
                    int ny = cur.Y + dy[dir];
                    if(nx<0||nx>=n||ny<0||ny>=m) continue;
                    if(vis[nx][ny] != 0 || board[nx][ny] != 1) continue;  
                    vis[nx][ny] = 1;
                    Q.push({nx,ny});
                }
            }
            cout << '\n';
        }
    }
    cout << '\n';
}
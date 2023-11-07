#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second 
string board[101];
int dis[101][101];
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m; cin >> n >> m;
    queue<pair<int, int>> Q;
    for(int i = 0; i < n;i++){
        cin >> board[i];
    }
    for(int i = 0;i < n;i++) fill(dis[i],dis[i]+m,-1); // fill 쓸때는 그냥 열 갯수만큼 더해주면 됌 
    dis[0][0]++;
    Q.push({0,0});
    while(!Q.empty())
    {
        pair<int, int> cur = Q.front();Q.pop();
        for(int dir = 0;dir < 4;dir++){
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];

            if(nx<0||nx>=n||ny<0||ny>=m) continue;
            if(dis[nx][ny] >= 0 || board[nx][ny] == '0') continue;
            dis[nx][ny] = dis[cur.X][cur.Y] + 1;
            Q.push({nx,ny});
        }
    }
    cout << dis[n-1][m-1] + 1 <<'\n';
}
// 시간 초과 

#include <bits/stdc++.h>
using namespace std;
#define X first 
#define Y second
#define MAX 1001
string board[MAX];
int dist[MAX][MAX];
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};
int n,m;
int min1 = 100000;
int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    queue<pair<int, int>> Q1;
    cin >> n >> m;
    for(int i = 0;i < n;i++){
        cin >> board[i];
    }
    for(int i = 0;i < n;i++){
        for(int j = 0;j < m;j++){
            if(board[i][j] == '1') Q1.push({i,j});
        }
    }
    int num = Q1.size();
    while(num--)
    {
        for(int i = 0; i< n;i++) fill(dist[i],dist[i]+m,-1);
        queue<pair<int,int>> Q2;
        pair<int,int> one = Q1.front(); Q1.pop();
        board[one.X][one.Y] = '0';
        dist[0][0] = 1;
        Q2.push({0,0});
        while(!Q2.empty()){
            pair<int, int> cur = Q2.front();Q2.pop();
            for(int dir = 0;dir < 4; dir++)
            {
                int nx = cur.X + dx[dir];
                int ny = cur.Y + dy[dir];
                if(nx<0||nx>=n||ny<0||ny>=m) continue;
                if(dist[nx][ny] >=0 || board[nx][ny] == '1') continue;
                dist[nx][ny] = dist[cur.X][cur.Y] + 1;
                Q2.push({nx,ny});
            }

        }
        if(dist[n-1][m-1] != -1) min1 = min(min1,dist[n-1][m-1]);
        board[one.X][one.Y] = '1';
    }
    // for(int i = 0; i < n;i++)
    // {
    //     for(int j = 0 ; j < m;j++){
    //         cout << dist[i][j] << ' ';
    //     }
    //     cout << '\n';
    // }
    if(min1 == 100000) cout << -1 <<'\n';
    else cout << min1 <<'\n';

}
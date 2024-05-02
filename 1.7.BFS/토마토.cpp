#include <bits/stdc++.h>
using namespace std;

#define X first 
#define Y second
#define MAX 1002

int board[MAX][MAX];
int dis[MAX][MAX];

int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

int main(void) {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    
    int time = 0;
    int n, m;
    cin >> m >> n;
    queue<pair<int, int>> Q; 
    for(int i = 0 ; i < n ; i++) fill(dis[i], dis[i] + m, -1);
    for(int i = 0 ; i  < n ; i++) {
        for(int j = 0; j < m; j++) {
            cin >> board[i][j];
            if(board[i][j] == 1) {
                Q.push({i,j});
                dis[i][j]++;
            }
        }
    }
    while(!Q.empty()) {
        pair<int, int> cur = Q.front();Q.pop();
        for(int i = 0 ; i < 4; i++) {
            int nx = cur.X + dx[i];
            int ny = cur.Y + dy[i];
            if (nx<0 || ny<0 || nx >= n || ny >= m) continue;
            if (dis[nx][ny] != -1 || board[nx][ny] != 0) continue;
            dis[nx][ny] = dis[cur.X][cur.Y] + 1;
            time = max(time, dis[nx][ny]);
            board[nx][ny] = 1;
            Q.push({nx,ny});
        }
    }
    for(int i = 0 ; i < n ; i++) {
        for(int j = 0 ; j < m ; j++) {
            if(board[i][j] == 0) {
                time = -1;
            }
        }
    }
    cout << time << '\n';

}
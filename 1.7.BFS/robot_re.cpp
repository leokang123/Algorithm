#include <bits/stdc++.h>
using namespace std;

int board[102][102];
int board2[102][102];
int cnt[102][102][4];
int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};
int dir[] = {0,2,1,3};
int n, m;

void showBoard(int x,int y) {
    board2[x][y] = 1;
    for(int i = 0 ; i < n ; i++) {
        for(int j = 0 ; j < m ; j++) cout << board2[i][j] << ' ';
        cout << '\n';
    }
    cout << cnt[x][y][0] << '\n';
    cout << cnt[x][y][2] << '\n';
    cout << '\n';
}
int main (void) {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cin >> n >> m ;
    for (int i = 0 ; i < n ; i++) for(int j = 0 ; j < m ; j++) cin >> board[i][j];
    
    int sx,sy,sd; cin >> sx >> sy >> sd;
    int ex,ey,ed; cin >> ex >> ey >> ed;
    queue<pair<int,int>> q;
    queue<pair<int,int>> q2;
    int p = 0, e = 0;
    for(;p<4;p++) if(dir[p] == sd-1) break;
    q.push({sx-1,sy-1});
    q2.push({p,0});
    cnt[sx-1][sy-1][dir[p]] = 1;
    while (!q.empty()) {
        auto [x, y] = q.front(); q.pop();
        auto [d, en] = q2.front(); q2.pop();
        cnt[x][y][dir[d]] = 1;
        if (x == ex-1 && y == ey-1 && dir[d] == ed-1) {
            cout << en << '\n';
            return 0;
        }
        for (int i = 1 ; i < 4 ; i++) {
            int nx = x + dx[dir[d]] * i, ny = y + dy[dir[d]] * i;
            if (nx < 0 || ny < 0 || nx >= n || ny >= m) break;
            if (cnt[nx][ny][dir[d]] || board[nx][ny]) break;
            q.push({nx,ny});
            q2.push({d,en +1});
        }
        for(auto i : {-1,1}) {
            int nd = (d + i + 4) % 4;
            if (cnt[x][y][dir[nd]]) continue;
            q.push({x,y});
            q2.push({nd,en+1});
        }
    }
}
// 다시 잘 생각하고 해보자 아무래도 직선으로출발할때 vis처리를 해주는게 맞을거같다 
// 무지성으로 덤비지 말고 제대로 준비해서 덤비자 
#include <bits/stdc++.h>
using namespace std;

int dx[5] = {0,0,0,1,-1};
int dy[5] = {0,1,-1,0,0};    
int n, m;
int sx, sy, sd;
int ex, ey, ed; 
int board[102][102];
int vis[102][102][5];
int cal(int k, int x,int y) {
    int ox = dx[k];
    int oy = dy[k];
    int i = 1;
    while(true) {
        int nx = x + i * ox;
        int ny = y + i * oy;
        if (nx < 1|| ny < 1 || nx > n || ny > m) break;
        if (vis[nx][ny][k] || board[nx][ny]) break;
        i++;
    }
    return i;
}
void showBoard() {
    for(int i = 1 ; i <= n ; i++) {
        for(int j = 1 ; j <= m ; j++) {
            cout << vis[i][j][3] << ' ';
        }
        cout << '\n';
    }
    cout << '\n';
}
int turnLeft (int k) {
    switch (k) {
        case 1:
        case 2:
            k = 5 - k;
            break;
        case 3:
        case 4:
            k -= 2;
            break;
    }
    return k;
}
int turnRight (int k) {
    switch (k) {
        case 1:
        case 2:
            k += 2;
            break;
        case 3:
        case 4:
            k = 5 - k;
            break;
    }
    return k;
}

int main (void) {
    cin.tie (nullptr);
    ios::sync_with_stdio(false);

    cin >> n >> m;
    for (int i = 1 ; i <= n ; i++) {
        for (int j = 1; j <= m ; j++) cin >> board[i][j];
    }
    cin >> sx >> sy >> sd;
    cin >> ex >> ey >> ed;
    // cout << cal(sd,sx,sy) << '\n';
    queue <pair<int,int>> q1;
    queue <pair<int,int>> q2;
    // 맨첨상황이랑 같은경우 예외처리 필요  
    vis[sx][sy][sd] = 1;
    q1.push({sx,sy});
    q2.push({sd, 0});
    while(!q1.empty()) {
        auto [cx, cy] = q1.front(); q1.pop();
        auto [cd, cn] = q2.front(); q2.pop();
        vis[cx][cy][cd] = 1;
        if (cx == ex && cy == ey && cd == ed) {
            cout << cn  << '\n';
            return 0;
        }
        for (int i = 0 ; i < 3 ; i++) {
            int nx = cx, ny = cy, nd = cd;
            if (i == 0) {
                int a = cal(nd, cx, cy);
                a = min (a, 4);
                for (int j = 1 ; j < a; j++) {
                    nx = cx + dx[nd] * j;
                    ny = cy + dy[nd] * j;
                    q1.push({nx,ny});
                    q2.push({nd,cn+1});
                }
            }
            else {
                if(i == 1) nd = turnLeft(cd);
                else nd = turnRight(cd);
                if (vis[nx][ny][nd]) continue;
                q1.push({nx,ny});
                q2.push({nd,cn+1});
            }
        }

    }
    return 0;
}

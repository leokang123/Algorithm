#include <bits/stdc++.h>
using namespace std;

#define MAX 1001
#define X get<0> (cur)
#define Y get<1> (cur)
#define Z get<2> (cur)

int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

int dis[11][MAX][MAX];
char board[MAX][MAX];

int main (void) {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    for(int i = 0 ; i < 11; i++) {
        for(int j = 0 ; j < MAX ; j++) {
            fill(dis[i][j], dis[i][j] + MAX, -1);
        }
    }

    int n, m, k;
    cin >> n >> m >> k;
    queue<tuple<int,int,int>> Q;
    Q.push({1,1,k});
    dis[k][1][1]++;
    for(int i = 1 ; i <= n ; i++) {
        for(int j = 1 ; j <= m ; j++) {
            cin >> board[i][j];
        }
    }
    if(n == 1 && m == 1) {
        cout << 1 << '\n';
        return 0;
    }
    while(!Q.empty()) {
        tuple <int,int,int> cur = Q.front(); Q.pop();
        for(int i = 0 ; i < 4 ; i++) {
            int nx = X + dx[i];
            int ny = Y + dy[i];
            int abil = Z;
            if(nx<1||ny<1||nx>n||ny>m) continue;
            if(nx == n && ny ==m) {
                cout << dis[abil][X][Y] + 2;
                return 0;
            }
            // 벽 부시는 능력 있고, 다음 갈 공간이 벽이고, 다른 데서 방문한적 없을때 
            if(abil > 0 && (dis[abil-1][nx][ny] == -1 && board[nx][ny] == '1')) {
                dis[abil-1][nx][ny] = dis[abil][X][Y] + 1;
                Q.push({nx,ny,abil-1});
            }
            if(dis[abil][nx][ny] != -1 || board[nx][ny] != '0') continue;
            dis[abil][nx][ny] = dis[abil][X][Y] + 1;
            Q.push({nx,ny,abil});
        }
    }
    cout << -1 << '\n';
}
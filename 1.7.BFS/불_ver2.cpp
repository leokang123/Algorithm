#include <bits/stdc++.h>
using namespace std;

#define MAX 1001
#define X get<0> (cur)
#define Y get<1> (cur)
#define Z get<2> (cur)

int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

char board[MAX][MAX];
int dis[MAX][MAX];

int main(void) {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    for(int i = 0 ; i < MAX ; i++) {
        fill(dis[i], dis[i] + MAX, -1);
    }
    // 0 불큐, 1 지수큐
    queue<tuple<int, int, char>> Q;
    int n, m; 
    cin >> n >> m;
    int a,b;
    for(int i = 0 ; i < n ; i++) {
        for(int j = 0 ; j < m ; j++) {
            cin >> board[i][j];
            if(board[i][j] == 'F') {
                dis[i][j] += 1;
                Q.push({i,j,'F'});
            }

            if(board[i][j] == 'J') {
                a = i;
                b = j;
            }
        }
    }

    // 지수는 모든 불 뒤에 와야함 
    dis[a][b] += 1;
    Q.push({a,b,'J'});

    while(!Q.empty()) {
        tuple<int, int, char> cur = Q.front(); Q.pop();
        for(int i = 0 ; i < 4 ; i++) {
            int nx = X + dx[i];
            int ny = Y + dy[i];
            char name = Z;

            // 배열을 벗어난경우 
            if(nx<0||ny<0||nx>=n||ny>=m) {
                // 벗어난주체가 지수면 잘 탈출했다는 의미니까 종료 
                if(name == 'J') {
                    cout << dis[X][Y] + 1 << '\n';
                    return 0;
                }
                continue;
            }
            if(dis[nx][ny] != -1 || board[nx][ny] != '.') continue;
            dis[nx][ny] = dis[X][Y] + 1;
            Q.push({nx,ny,name});
        }
    }
    cout << "IMPOSSIBLE" << '\n';
    return 0;
}

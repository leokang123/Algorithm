#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second
#define MAX 1001


int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

char board[MAX][MAX];
int dist1[MAX][MAX];
int dist2[MAX][MAX];

int main(void) {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int n,m;
    int success = 0;
    cin >> n >> m;
    queue<pair<int, int>> Q[2];
    for(int i = 0 ; i < n ; i++){
        fill(dist1[i], dist1[i] + m, -1);
        fill(dist2[i], dist2[i] + m, -1);
    }

    for(int i = 0 ; i < n ; i++) {
        for(int j = 0 ; j < m ; j++) {
            cin >> board[i][j];
            if(board[i][j] == 'J') {
                Q[0].push({i,j});
                dist1[i][j]++;
            }
            if(board[i][j] == 'F') {
                Q[1].push({i,j});
                dist2[i][j]++;
            }
        }
    }
    while(!Q[1].empty()) {
        pair<int, int> cur = Q[1].front();Q[1].pop();
        for(int i = 0 ; i < 4 ; i++) {
            int nx = cur.X + dx[i];
            int ny = cur.Y + dy[i];
            if(nx<0 || ny<0 || nx>=n || ny>=m) continue;
            if(board[nx][ny] != '.' || dist2[nx][ny] != -1) continue;
            dist2[nx][ny] = dist2[cur.X][cur.Y] + 1;
            Q[1].push({nx,ny});
        }
    }
    while(!Q[0].empty()) {
        pair<int, int> cur = Q[0].front();Q[0].pop();
        for(int i = 0 ; i < 4 ; i++) {
            int nx = cur.X + dx[i];
            int ny = cur.Y + dy[i];
            // 처음에 가장자리에 지수가 있으면 그걸 바로 밖으로 보내주기 위해서는 아래 조건식에서 처리해줘야한다 
            if(nx<0 || ny<0 || nx>=n || ny>=m) {
                cout << dist1[cur.X][cur.Y] + 1;
                return 0;
            }
            if(board[nx][ny] != '.' || dist1[nx][ny] != -1) continue;
            if(dist2[nx][ny] != -1 && dist1[cur.X][cur.Y] + 1 >= dist2[nx][ny]) continue;
            dist1[nx][ny] = dist1[cur.X][cur.Y] + 1;

            // 이렇게 아래에서 처리를 해주며 가장자리에 지수가 있는경우에 대해서 처리를 못함
            // if(!success && (nx == 0 || ny == 0 || nx == n-1 || ny == m-1)) {
            //     success = 1;
            //     cout << dist1[nx][ny] + 1;
            // }
            Q[0].push({nx,ny});
        }
    }
    if(!success) {
        cout << "IMPOSSIBLE" << '\n';
    }

    return 0;
}
#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second 
#define MAX 25

int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

int arr[MAX * MAX / 2];
string board[MAX];
int vis[MAX][MAX];

int main(void) {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n;
    cin >> n;
    for(int i = 0 ; i < n ; i++) {
        cin >> board[i];
    }

    int index = 0;
    queue<pair<int, int>> Q;
    for(int i = 0 ; i < n ; i++) {
        for(int j = 0 ; j < n ; j++) {
            if(board[i][j] != '1' || vis[i][j] != 0) continue;
            int time = 1;
            vis[i][j] = 1;
            Q.push({i,j});
            while(!Q.empty()) {
                pair<int, int> cur = Q.front(); Q.pop();
                for(int i = 0 ; i < 4 ; i++) {
                    int nx = cur.X + dx[i];
                    int ny = cur.Y + dy[i];
                    if(nx<0 || ny<0 || nx>=n || ny>=n) continue;
                    if(board[nx][ny] != '1' || vis[nx][ny] != 0) continue;
                    time++;
                    vis[nx][ny] = 1;
                    Q.push({nx,ny});
                }
            }
            arr[index++] = time;
        }
    }
    sort(arr, arr+ index);
    cout << index << '\n';
    for(int i = 0 ; i < index ; i++) {
        cout  << arr[i] << '\n';
    }
}
#include <bits/stdc++.h>
using namespace std;
#define MAX 1001

int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};
string b[MAX];
int board[MAX][MAX];
int vis[MAX][MAX];
int vis2[MAX * MAX];

int main (void) {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int n, m; cin >> n >> m;
    for(int i = 0 ; i < n ; i++) fill(vis[i],vis[i] + m+1, -1);
    for(int i = 0 ; i < n ; i++) {
        cin >> b[i];
    }

    for(int i = 0 ; i < n ; i++) {
        for(int j = 0 ; j < m ; j++) {
            if(b[i][j] == '1') board[i][j] = 1;
            else board[i][j] = 0;
        }
    }

    queue<pair<int, int>> q;
    int num = 0, cnt = 0;
    for(int i = 0 ; i < n ; i++) {
        for(int j = 0 ; j < m ; j++) {
            if(board[i][j] == 1 || vis[i][j] != -1) continue;
            cnt = 0;
            vis[i][j] = num;
            q.push({i,j});
            while(!q.empty()) {
                pair<int, int> cur = q.front();q.pop();
                cnt++;
                for(int i = 0 ; i < 4 ; i++) {
                    int nx = cur.first + dx[i];
                    int ny = cur.second + dy[i];
                    if(nx < 0 || ny < 0 || nx >= n || ny >=m) continue;
                    if(vis[nx][ny] == num || board[nx][ny] != 0) continue;
                    vis[nx][ny] = num;
                    q.push({nx,ny});
                }
            }
            vis2[num++] = cnt;
        }
    }
    
    for(int i = 0 ; i < n ; i++) {
        for(int j = 0 ; j < m ; j++) {
            if(board[i][j] != 1) continue;
            cnt = 1;
            int arr[MAX * MAX] = {0,};
            for(int s = 0 ; s < 4 ; s++) {
                int nx = i + dx[s];
                int ny = j + dy[s];
                if(nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
                int conti = vis[nx][ny];
                if(conti == -1 || arr[conti] == 1) continue;
                cnt += vis2[conti];
                arr[conti] = 1;
            }
            board[i][j] = cnt;
        }
    }
    for(int i = 0 ; i < n; i++) {
        for(int j = 0 ; j < m ; j++) {
            cout << board[i][j];
        }
        cout << '\n';
    }
    return 0;
}

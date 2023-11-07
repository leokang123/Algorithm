#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second 
#define MAX 101
string board[MAX];
int vis[MAX][MAX];
int vis2[MAX][MAX];
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};
int N;
int red,green,blue,rg;
int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N;
    queue<pair<int, int>> Q;
    for(int i = 0 ;i< N;i++) cin >> board[i];
    for(int i = 0;i < N;i++){
        for(int j = 0;j < N;j++){
            if(vis[i][j] != 0 || board[i][j] != 'R') continue;
            vis[i][j] = 1;
            
            Q.push({i,j});
            red++;
            while(!Q.empty()){
                pair<int, int> cur = Q.front();Q.pop();
                for(int dir = 0; dir < 4; dir++){
                    int nx = cur.X + dx[dir];
                    int ny = cur.Y + dy[dir];
                    if(nx<0||nx>=N||ny<0||ny>=N) continue;
                    if(vis[nx][ny] != 0 || board[nx][ny] != 'R') continue;
                    vis[nx][ny] = 1;
                    
                    Q.push({nx,ny});
                }
            }
        }
    }
    for(int i = 0;i < N;i++){
        for(int j = 0;j < N;j++){
            if(vis[i][j] != 0 || board[i][j] != 'B') continue;
            vis[i][j] = 1;
            vis2[i][j] = 1;
            Q.push({i,j});
            blue++;
            while(!Q.empty()){
                pair<int, int> cur = Q.front();Q.pop();
                for(int dir = 0; dir < 4; dir++){
                    int nx = cur.X + dx[dir];
                    int ny = cur.Y + dy[dir];
                    if(nx<0||nx>=N||ny<0||ny>=N) continue;
                    if(vis[nx][ny] != 0 || board[nx][ny] != 'B') continue;
                    vis[nx][ny] = 1;
                    vis2[nx][ny] = 1;
                    Q.push({nx,ny});
                }
            }
        }
    }
    for(int i = 0;i < N;i++){
        for(int j = 0;j < N;j++){
            if(vis[i][j] != 0 || board[i][j] != 'G') continue;
            vis[i][j] = 1;
            Q.push({i,j});
            green++;
            while(!Q.empty()){
                pair<int, int> cur = Q.front();Q.pop();
                for(int dir = 0; dir < 4; dir++){
                    int nx = cur.X + dx[dir];
                    int ny = cur.Y + dy[dir];
                    if(nx<0||nx>=N||ny<0||ny>=N) continue;
                    if(vis[nx][ny] != 0 || board[nx][ny] != 'G') continue;
                    vis[nx][ny] = 1;
                    Q.push({nx,ny});
                }
            }
        }
    }
    for(int i = 0;i < N;i++){
        for(int j = 0;j < N;j++){
            if(vis2[i][j] != 0 || board[i][j] == 'B') continue;
            vis2[i][j] = 1;
            Q.push({i,j});
            rg++;
            while(!Q.empty()){
                pair<int, int> cur = Q.front();Q.pop();
                for(int dir = 0; dir < 4; dir++){
                    int nx = cur.X + dx[dir];
                    int ny = cur.Y + dy[dir];
                    if(nx<0||nx>=N||ny<0||ny>=N) continue;
                    if(vis2[nx][ny] != 0 || board[nx][ny] == 'B') continue;
                    vis2[nx][ny] = 1;
                    Q.push({nx,ny});
                }
            }
        }
    }
    cout << red+blue+green << ' ' << rg+blue<<'\n';
}
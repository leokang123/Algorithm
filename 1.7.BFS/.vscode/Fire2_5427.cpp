#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second
#define MAX 1001 
string board[MAX];
int dist1[MAX][MAX];
int dist2[MAX][MAX];
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};
int T,w,h;
bool istrue;
int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    pair<int, int> pos;
    cin>> T;
    while(T--){
        istrue = 0;
        cin >> w >> h;
        queue<pair<int, int>> Q;
        for(int i = 0; i < h;i++){
            fill(dist1[i],dist1[i] + w,-1);
            fill(dist2[i],dist2[i] + w,-1);
        }
        for(int i = 0; i < h;i++){
            cin >> board[i];
        }
        for(int i = 0; i < h;i++){
            for(int j = 0; j < w;j++){
                if(board[i][j] == '*') {
                    dist1[i][j]++;
                    Q.push({i,j});
                }
                if(board[i][j] == '@') pos = {i,j};
            }
        }
        while(!Q.empty()){
            pair<int, int> cur = Q.front();Q.pop();
            for(int dir = 0;dir < 4;dir++){
                int nx = cur.X + dx[dir];
                int ny = cur.Y + dy[dir];
                if(nx<0||nx>=h||ny<0||ny>=w) continue;
                if(dist1[nx][ny] >=0 || board[nx][ny] == '#') continue;
                dist1[nx][ny] = dist1[cur.X][cur.Y] + 1;
                Q.push({nx,ny});
            }
        }
        dist2[pos.X][pos.Y]++;
        Q.push(pos);
        while(!Q.empty()){
            if(istrue) break;
            pair<int, int> cur = Q.front();Q.pop();
            for(int dir = 0;dir < 4;dir++){
                int nx = cur.X + dx[dir];
                int ny = cur.Y + dy[dir];
                if(nx<0||nx>=h||ny<0||ny>=w){
                    istrue = 1;
                    cout << dist2[cur.X][cur.Y] + 1 << '\n';
                    break;
                }
                if(dist2[nx][ny] >=0 || board[nx][ny] == '#') continue;
                if(dist1[nx][ny] != -1 && dist1[nx][ny] <= dist2[cur.X][cur.Y] + 1) continue;
                dist2[nx][ny] = dist2[cur.X][cur.Y] + 1;
                Q.push({nx,ny});
            }
        }
        if(!istrue) cout << "IMPOSSIBLE" << '\n';
    }
}
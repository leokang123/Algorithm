#include <bits/stdc++.h>
using namespace std;
#define X first 
#define Y second 
#define MAX 301
int board[MAX][MAX];
int vis[MAX][MAX];
int N,M;
int first;
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};
int num;
int main(void){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N >> M;
    queue<pair<int, int>> Q;
    for(int i = 0;i<N;i++){
        for(int j = 0;j<M;j++) cin >> board[i][j];
    }
    int count = 0;
    int total = 0;
    while(count != -1){
        total++;
        first = 1;
        num = 0;
        count = 0;
        for(int i = 0;i < N;i++) fill(vis[i],vis[i] + M,0);
        for(int i = 0;i<N;i++){
            for(int j = 0;j<M;j++){
                if(board[i][j] != 0) {
                    if(first){
                        vis[i][j] = 1;
                        Q.push({i,j});
                        count++;
                        first = 0;
                    }
                    num++;
                }
            }
        }
        int zeronum = 0;
        while(!Q.empty()){
            pair<int,int> cur = Q.front(); Q.pop();
            zeronum = 0;
            for(int dir=0;dir<4;dir++){
                int nx = cur.X + dx[dir];
                int ny = cur.Y + dy[dir];
                if(nx<0||nx>=N||ny<0||ny>=M) continue;
                if(vis[nx][ny] == 0 && board[nx][ny] == 0) zeronum++;
                if(dir == 3) board[cur.X][cur.Y] = (board[cur.X][cur.Y] - zeronum <= 0)? 0 : board[cur.X][cur.Y] - zeronum ;
                if(vis[nx][ny] != 0) continue;
                if(board[nx][ny] != 0){
                    vis[nx][ny] = 1;
                    Q.push({nx,ny});
                    count++;
                }
            }
        }
        if(count < num) count = -1;
        cout << count <<','<<num<<'\n';
        // for(int i = 0; i< N;i++){
        //     for(int j = 0; j<M;j++){
        //         cout << board[i][j] <<' ';
        //     }
        //     cout <<'\n';
        // }
    }
    cout << total-1 <<'\n';
}
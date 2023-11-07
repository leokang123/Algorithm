#include <bits/stdc++.h>
using namespace std;
#define X first 
#define Y second
#define MAX 101
int board[MAX][MAX][MAX];
int dist[MAX][MAX][MAX];
int M,N,H;
int time1;
int dx[6] = {1,0,-1,0,0,0};
int dy[6] = {0,1,0,-1,0,0};
int dz[6] = {0,0,0,0,1,-1};

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> M >> N >> H;
    queue<tuple<int, int, int>>Q;
    for(int z = 0;z < H; z++){
        for(int i = 0;i < N;i++){
            fill(dist[z][i],dist[z][i] + M,-1);
        }
    }
    for(int z = 0;z < H; z++){
        for(int i = 0;i < N;i++){
            for(int j = 0; j < M;j++){
                cin >> board[z][i][j];
                if(board[z][i][j] == 1){
                    dist[z][i][j]++;
                    Q.push({z,i,j});
                }
            }
        }
    }
    while(!Q.empty()){
        tuple<int, int, int> cur = Q.front();Q.pop();
        for(int dir = 0;dir < 6; dir++){
            int nz = get<0>(cur) + dz[dir];
            int nx = get<1>(cur) + dx[dir];
            int ny = get<2>(cur) + dy[dir];

            if(nx<0||nx>=N||ny<0||ny>=M||nz<0||nz>=H) continue;
            if(dist[nz][nx][ny] >= 0 || board[nz][nx][ny] == -1) continue;
            dist[nz][nx][ny] = dist[get<0>(cur)][get<1>(cur)][get<2>(cur)] + 1;
            time1 = max(time1,dist[nz][nx][ny]);
            Q.push({nz,nx,ny});
        }
    }

    for(int z = 0;z < H;z++){
        for(int i = 0;i<N;i++){
            for(int j=0;j<M;j++){
                if(dist[z][i][j] == -1 && board[z][i][j] == 0){
                    cout << -1 <<'\n';
                    return 0;
                }
            }
        }
    }
    cout << time1 << '\n';

}
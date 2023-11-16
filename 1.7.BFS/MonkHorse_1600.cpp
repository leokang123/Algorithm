#include <bits/stdc++.h>
using namespace std;
#define MAX 201
#define X(cur) get<0> (cur)
#define Y(cur) get<1> (cur)
#define ABIL(cur) get<2> (cur)
int board[MAX][MAX];
int dist[30][MAX][MAX];
int dx[4] = {1,0,-1,0};
int dx2[8] = {2,2,1,-1,-2,-2,-1,1};
int dy[4] = {0,1,0,-1};
int dy2[8] = {-1,1,2,2,1,-1,-2,-2};
int K;
int min1;

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> K;
    int n,m; cin >> m >> n; // m 이 가로길이(열) , n이 세로길이 (행))
    for(int i = 0;i < K+1;i++){ // 능력이 1개 있다고 할떄 배열갯수는 2개 필요하니까 
        for(int j = 0;j < n;j++) fill(dist[i][j],dist[i][j] + m,-1);
    }
    for(int i = 0;i < n;i++){
        for(int j = 0;j < m;j++){
            cin >> board[i][j];
        }
    }
    min1 = 1000;
    queue<tuple<int,int,int>> Q;
    for(int i = 0 ;i < K+1 ; i++) dist[i][0][0] = 0;
    Q.push({0,0,K});
    while(!Q.empty()){
        tuple<int,int,int> cur = Q.front();Q.pop();
        int nx = X(cur);
        int ny = Y(cur);
        int nk = ABIL(cur);
        if(nx == n-1 && ny == m-1){
            if(dist[nk][nx][ny] != -1){
                cout << dist[nk][nx][ny] << '\n';
                return 0;
            }
        }
        if(nk > 0){
            for(int dir=0;dir < 8;dir++){
                int nx2 = nx + dx2[dir];
                int ny2 = ny + dy2[dir];
                if(nx2<0||nx2>=n||ny2<0||ny2>=m) continue; 
                if(dist[nk-1][nx2][ny2] >= 0|| board[nx2][ny2] != 0) continue;
                dist[nk-1][nx2][ny2] = dist[nk][nx][ny] + 1;
                Q.push({nx2,ny2,nk-1});
            }
        }
        for(int dir = 0 ; dir < 4; dir++){
            int nx3 = X(cur) + dx[dir];
            int ny3 = Y(cur) + dy[dir];
            int nk = ABIL(cur);
            if(nx3<0||nx3>=n||ny3<0||ny3>=m) continue;
            if(dist[nk][nx3][ny3] >= 0 || board[nx3][ny3] != 0) continue;
            dist[nk][nx3][ny3] = dist[nk][X(cur)][Y(cur)] + 1;
            Q.push({nx3,ny3,nk});
        }

    }
    cout << -1 <<'\n';

}
#include <bits/stdc++.h>
using namespace std;
#define X first 
#define Y second 
#define MAX 301
int board[MAX][MAX];
int vis[MAX][MAX];
int N,M;
int first;
int first_num;
int num;
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};
int main(void){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N >> M;
    queue<pair<int, int>> Q;
    for(int i = 0;i<N;i++){
        for(int j = 0;j<M;j++) {
            cin >> board[i][j];
            if(board[i][j] != 0 ) num++; // 처음 대륙크기 
        }
    }
    int first_num; 
    int count = 0; // BFS순회하면서 찾은 대류크기 
    int total = 0;
    while(count != -1){
        if(num == 0) break;
        first_num = num; // 빙산 녹기 전 크기 
        total++; // n-1년차 
        first = 1; // 첫 0 이 아닌 대륙 찾기위한 변수 
        count = 0;
        for(int i = 0;i < N;i++) fill(vis[i],vis[i] + M,0); // 방문배열 초기화 
        for(int i = 0;i<N;i++){
            for(int j = 0;j<M;j++){
                if(board[i][j] != 0) {
                    if(first){
                        vis[i][j] = 1;
                        Q.push({i,j});
                        count++;
                        first = 0;
                    }
                }
            }
        }
        int zeronum = 0;
        while(!Q.empty()){
            pair<int,int> cur = Q.front(); Q.pop();
            // cout << board[cur.X][cur.Y]<<' ';
            zeronum = 0;
            for(int dir=0;dir<4;dir++){
                int nx = cur.X + dx[dir];
                int ny = cur.Y + dy[dir];
                if(nx<0||nx>=N||ny<0||ny>=M) continue;
                if(vis[nx][ny] == 0 && board[nx][ny] == 0) zeronum++; // 방문하지 않고 0인 노드 
                if(dir == 3){
                    if(board[cur.X][cur.Y] <= zeronum){
                        num--; // 대륙 0 되면 전체 대륙크기에서 -1 
                        board[cur.X][cur.Y] = 0;
                    }else{
                        board[cur.X][cur.Y] -= zeronum;
                    }
                }
                if(vis[nx][ny] != 0) continue;
                if(board[nx][ny] != 0){ 
                    vis[nx][ny] = 1;
                    Q.push({nx,ny});
                    count++;
                }
            }
        }
        // cout << count<<','<<first_num<<' '<<num<<'\n';
        if(count < first_num) count = -1; // 탈출조건 
        // for(int i = 0; i< N;i++){
        //     for(int j = 0;j < M;j++){
        //         cout << board[i][j] << ' ';
        //     }
        //     cout << '\n';
        // }
    }
    if(num == 0) cout << 0 <<'\n';
    else cout << total - 1 <<'\n';
}
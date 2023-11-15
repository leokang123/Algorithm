#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second 
#define MAX 101
int board[MAX][MAX];
int vis[MAX][MAX];
int dist[MAX][MAX]; // 일단 만들어놔바 
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};
int main(void){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int num;cin >> num;
    int first = 1;
    int end1 = 0;
    int min1 = 10000;
    queue<pair<int,int>> Q3;
    queue<pair<int,int>> Q1;
    queue<pair<int,int>> Q2;
    for(int i = 0 ; i < num; i++) fill(dist[i], dist[i] + num, -1);
    for(int i = 0;i < num;i++){
        for(int j = 0;j < num;j++){
            cin >> board[i][j];
            if(board[i][j] == 1 && first){
                Q1.push({i,j});
                vis[i][j] = 1;
                dist[i][j]++;
                first = 0;
            }
        }
    }
    while(true){
        //무조건 초기화 시켜줘야하네 괜히 머리속으로 안해도 되지 않나 생각하다..
        // 그럼 그냥 dist배열 없이 튜플로 거리를 재도되겠다 
        for(int i = 0;i < num;i++) fill(dist[i],dist[i] + num,-1);
        while(!Q1.empty()){
            pair<int,int> cur = Q1.front();Q1.pop(); // pop을 시키지 않고는 순횔르 돌기 어렵다 
            dist[cur.X][cur.Y] = 0;
            Q3.push(cur); // 차라리 다른 큐에 저장하는 식으로 짜야함 
            for(int dir = 0; dir < 4; dir++){
                int nx = cur.X + dx[dir]; 
                int ny = cur.Y + dy[dir];
                if(nx<0||nx>=num||ny<0||ny>=num)continue;
                if(dist[nx][ny]>=0 || board[nx][ny] == 0) continue;
                dist[nx][ny] = 0;
                vis[nx][ny] = 1;
                Q1.push({nx,ny});
            }
        }
        while(!Q3.empty()){
            pair<int,int> cur = Q3.front();Q3.pop();
            for(int dir = 0;dir < 4;dir++){
                int nx = cur.X + dx[dir];
                int ny = cur.Y + dy[dir];
                
                if(nx<0||nx>=num||ny<0||ny>=num) continue;
                if(dist[nx][ny]>=0 || vis[nx][ny] != 0) continue;
                if(board[cur.X][cur.Y] == 0 && board[nx][ny] == 1){
                    min1 = min(min1, dist[cur.X][cur.Y]);
                    dist[nx][ny] = 0;
                    vis[nx][ny] = 1;
                    while(!Q3.empty()) Q3.pop();
                    Q1.push({nx,ny});
                    break;
                }
                if(board[nx][ny] != 1){
                    dist[nx][ny] = dist[cur.X][cur.Y] + 1;
                    Q3.push({nx,ny});
                }
            }
        }
        
        if(Q1.empty()) break;
    }
    if(min1 != 10000 )cout << min1 <<'\n';
    else cout << 0 <<'\n';

}
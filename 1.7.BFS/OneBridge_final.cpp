// 튜플 버전 
#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second 
#define MAX 101
int board[MAX][MAX];
int vis[MAX][MAX];
int vis2[MAX][MAX]; // 일단 만들어놔바 
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};
int main(void){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int num;cin >> num;
    int first = 1;
    int end1 = 0;
    int min1 = 10000;
    queue<pair<int,int>> Q1;
    queue<tuple<int,int,int>> Q3;
    for(int i = 0;i < num;i++){
        for(int j = 0;j < num;j++){
            cin >> board[i][j];
            if(board[i][j] == 1 && first){
                Q1.push({i,j});
                vis[i][j] = 1;
                first = 0;
            }
        }
    }
    while(true){
        //무조건 초기화 시켜줘야하네 괜히 머리속으로 안해도 되지 않나 생각하다..
        // 그럼 그냥 dist배열 없이 튜플로 거리를 재도되겠다 
        for(int i = 0 ; i < num; i ++) fill(vis2[i],vis2[i] + num,0);
        // 결국 방문배열을 하나 더 만들기도 해야하고 초기화도 시켜야해서 큰 차이 없음 
        // 오히려 dist쓸때가 굳이 tuple도 안쓰고 좋은거 같음 
        while(!Q1.empty()){
            pair<int,int> cur = Q1.front();Q1.pop(); // pop을 시키지 않고는 순횔르 돌기 어렵다 
            tuple<int,int,int> foo = {cur.X,cur.Y,0};
            Q3.push(foo); // 차라리 다른 큐에 저장하는 식으로 짜야함 
            vis2[cur.X][cur.Y] = 1;
            for(int dir = 0; dir < 4; dir++){
                int nx = cur.X + dx[dir]; 
                int ny = cur.Y + dy[dir];
                if(nx<0||nx>=num||ny<0||ny>=num)continue;
                if(vis[nx][ny] != 0 || board[nx][ny] == 0) continue;
                vis[nx][ny] = 1;
                Q1.push({nx,ny});
            }
        }
        while(!Q3.empty()){
            tuple<int,int,int> cur = Q3.front();Q3.pop();
            // dist[cur.X][cur.Y] = 0;
            for(int dir = 0;dir < 4;dir++){
                int nx = get<0>(cur) + dx[dir];
                int ny = get<1>(cur)+ dy[dir];
                int distance = get<2>(cur);
                if(nx<0||nx>=num||ny<0||ny>=num) continue;
                if(vis[nx][ny] != 0 || vis2[nx][ny] != 0) continue;
                if(board[get<0>(cur)][get<1>(cur)] == 0 && board[nx][ny] == 1){
                    min1 = min(min1, distance);
                    while(!Q3.empty()) Q3.pop();
                    vis[nx][ny] = 1;
                    Q1.push({nx,ny});
                    break;
                }
                if(board[nx][ny] != 1){
                    vis2[nx][ny] = 1;
                    Q3.push({nx,ny,distance+1});
                }
            }
        }
        
        if(Q1.empty()) break;
    }
    if(min1 != 10000 )cout << min1 <<'\n';
    else cout << 0 <<'\n';

}
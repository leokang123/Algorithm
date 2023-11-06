#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second 
int board[502][502]; // 1이면 파랑칸, 0 이면 빨간칸이라 이해 
bool vis[502][502]; 
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1}; // 상하좌우를 영리하게 처리 아래,오른,위,왼 순 
int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    queue<pair<int, int>> Q;
    int n = 0,m = 0; cin >> n >> m;
    for(int i = 0;i < n;i++){
        for(int j = 0;j < m;j++){
            cin >> board[i][j];
        }
    }
    
    int size = 0, max = 0,num = 0;
    for(int i = 0;i < n;i++){
        for(int j = 0;j < m;j++){
            if(vis[i][j] == 1 || board[i][j] == 0) continue;
            // 배열을 돌면서 방문하지 않고 1로 적힌 곳을 방문한다 
            vis[i][j] = 1;
            Q.push({i,j});num++;
            size = 0;
            while(!Q.empty())
            {
                pair<int, int> cur = Q.front(); Q.pop();size++;
                // cout << '(' << cur.X <<", "<<cur.Y <<") -> ";
                for(int dir = 0;dir < 4;dir++){
                    // 보통 x,y 는 행,열 임 
                    int nx = cur.X + dx[dir];
                    int ny = cur.Y + dy[dir];
                    if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
                    if(vis[nx][ny] || board[nx][ny] != 1) continue;
                    vis[nx][ny] = 1; // 큐에 넣을때 방문표시를 남겨야한다 , 뺼때 남기면 안됌 
                    Q.push({nx,ny});
                }
            }
            if(max <= size) max = size;
        }
    }
    cout << num << '\n';
    cout << max <<'\n';
}
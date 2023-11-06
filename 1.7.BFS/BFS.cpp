#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second 
int board[502][502] = {...}; // 1이면 파랑칸, 0 이면 빨간칸이라 이해 
bool vis[502][502]; 
int n = 7,m = 10;
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1}; // 상하좌우를 영리하게 처리 아래,오른,위,왼 순 
int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    queue<pair<int, int>> Q;
    vis[0][0] = 1; // 시작점을 방문했다는 표시를 한다 
    Q.push(0,0);
    while(!Q.empty())
    {
        pair<int, int> cur = Q.front(); Q.pop();
        cout << '(' << cur.X <<", "<<cur.Y <<") -> ";
        for(int dir = 0;dir < 4;dir++){
            // 보통 x,y 는 행,열 임 
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];
            if(nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
            if(vis[nx][ny] || board[nx][ny] != 1) continue;
            vis[nx][ny] = 1; // 큐에 넣을때 방문표시를 남겨야한다 , 뺼때 남기면 안됌 
            Q.push({nx,ny});
        }
    }
}
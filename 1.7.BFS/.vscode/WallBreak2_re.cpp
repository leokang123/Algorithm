#include <bits/stdc++.h>
using namespace std;
#define X get<0> (cur)
#define Y get<1> (cur)
#define ONE get<2> (cur)
#define MAX 1001 
string board[MAX];
int dist[2][MAX][MAX];
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};
int n,m;
int hasone;
int distance1;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m;
    for(int i = 0;i < 2;i++){
        for(int j =0;j < n;j++){
            fill(dist[i][j],dist[i][j] + m,-1);
        }
    }
    for(int i = 0;i < n;i++){
        cin >> board[i];
    }
    if(n == 1 && m ==1) {
        cout << 1 <<'\n';
        return 0;
    }
    queue<tuple<int,int,int>> Q;
    dist[1][0][0] = 1;
    Q.push({0,0,1});
    while(!Q.empty())
    {
        tuple<int, int, int> cur = Q.front(); Q.pop();
        for(int dir = 0;dir < 4; dir++){
            int nx = X + dx[dir];
            int ny = Y + dy[dir];
            hasone = ONE;
            distance1 = dist[hasone][X][Y] + 1;
            if(nx == n-1 && ny == m-1){
                cout << distance1 <<'\n';
                return 0;
            }
            if(nx<0||nx>=n||ny<0||ny>=m) continue;
            if(board[nx][ny] == '1' && hasone == 1 && dist[0][nx][ny] == -1){
                dist[0][nx][ny] = distance1;
                Q.push({nx,ny,0});
            }
            if(board[nx][ny] == '0' && dist[hasone][nx][ny] == -1){
                dist[hasone][nx][ny] = distance1;
                Q.push({nx,ny,hasone});
            }
        }
    }
    cout << -1 <<'\n';
    return 0;
}
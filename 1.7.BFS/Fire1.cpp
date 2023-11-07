#include <bits/stdc++.h>
using namespace std;
#define X first 
#define Y second 
string board[1002];
int dist1[1002][1002];
int dist2[1002][1002];
int n, m;
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};
int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m;
    for(int i = 0;i<n;i++)
    {
        fill(dist1[i],dist1[i]+m,-1);
        fill(dist2[i],dist2[i]+m,-1);
    }
    for(int i =0;i<n;i++) cin >> board[i];
    queue<pair<int, int>> Q1;
    queue<pair<int, int>> Q2;
    for(int i = 0;i<n;i++){
        for(int j = 0;j<m;j++){
            if(board[i][j] == 'F'){
                dist1[i][j]++;
                Q1.push({i,j});
            }
            if(board[i][j] == 'J'){
                dist2[i][j]++;
                Q2.push({i,j});
            }
        }
    }
    while(!Q1.empty()){
        auto cur = Q1.front();Q1.pop();
        for(int dir = 0;dir < 4;dir++){
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];
            if(nx<0||nx>=n||ny<0||ny>=m) continue;
            if(dist1[nx][ny] >= 0 || board[nx][ny] == '#') continue;
            dist1[nx][ny] = dist1[cur.X][cur.Y] + 1;
            Q1.push({nx,ny});
        }
    }
    for(int i = 0;i<n;i++)
    {
        for(int j = 0;j<m;j++)
        {
            cout << dist1[i][j] << ' ';
        }
        cout << '\n';
    }
    while(!Q2.empty()){
        auto cur = Q2.front();Q2.pop();
        for(int dir = 0;dir < 4;dir++){
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];
            if(nx<0||nx>=n||ny<0||ny>=m){
                cout << dist2[cur.X][cur.Y] + 1 << '\n';;
                return 0; // BFS는 순서대로 커지는 특징이 있어 가장 먼저 탈출하는 것이 최단거리다 
            }
            if(dist2[nx][ny] >=0 || board[nx][ny] == '#') continue; // 방문 안한 dist2탐색 and  벽아닌데 탐색 
            if(dist1[nx][ny] != -1 && dist1[nx][ny] <= dist2[cur.X][cur.Y]+1) continue;
            // dist1[nx][ny] != -1 이게 왜 필요한지 모르겠음 근데 또 없으면 틀림
            // 저 조건 빼고 위에 조건식 board[nx][ny] == '#' || dist2[nx][ny] >=0 로도 해봄 틀림 
            // 근데 board[nx][ny] != '#' 이 말이 dist1[nx][ny] != -1 이말이랑 똑같은거 아닌가 
            // 똑같은게 아닌가 본데.. board[nx][ny] != '#' && dist1[nx][ny] <= dist2[cur.X][cur.Y]+1
            // 이렇게 놓고하면 틀렷다함 -> 아 벽만 -1 되는게 아니고 경로상 불가능한 경로는 전부 -1이 되는구나.. 
            // 말 그대로 dist는 시작점에서 갈수있는 최단 거리를 말하는거고 -1은 말그대로 시작점에서 갈수 없는 곳을 의미한다고 
            // 이해하면 되겠네.. 최대한 그냥 쪼개서 생각하자 
            dist2[nx][ny] = dist2[cur.X][cur.Y] + 1;
            Q2.push({nx,ny});
        }
    }

    cout << "IMPOSSIBLE\n";
    return 0;

}
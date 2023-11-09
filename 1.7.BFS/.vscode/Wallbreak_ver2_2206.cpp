#include <bits/stdc++.h>
using namespace std;
#define X get<0> (cur)
#define Y get<1> (cur)
#define ONE get<2> (cur)
#define MAX 1001
string board[MAX];
bool vis[MAX][MAX];
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};
int n, m;
int min1 = 10000;
int dis = 0;
int main(void)
{
    cin >> n >> m;
    stack<tuple<int, int, int>> Q;
    vector<pair<int, int>> V;
    for(int i = 0;i<n;i++) cin>>board[i];
    vis[0][0] = 1;
    V.push_back({0,0}); // 경로 저장 
    Q.push({0,0,1});
    while(!Q.empty()){
        for(auto i : V) vis[i.first][i.second] = 0;
        dis = 1;
        tuple<int,int,int> cur;
        for(int dir = 0; dir < 4;dir++)
        {
            cur = Q.top();
            int nx = X + dx[dir];
            int ny = Y + dy[dir];
            int hasone = ONE;
            if(nx<0||nx>=n||ny<0||ny>=m) continue;
            if(vis[nx][ny]!= 0) continue;
            if(board[nx][ny] == '1'){
                if(hasone != 1) continue;
                vis[nx][ny] = 1;
                V.push_back({nx,ny});
                Q.push({nx,ny,0});
            }else{
                vis[nx][ny] = 1;
                V.push_back({nx,ny});
                Q.push({nx,ny,hasone});
            }
            dis++;
        }
        min1 = min(dis,min1);
        Q.pop();
    }
    cout << min1;
}


#include <bits/stdc++.h>
using namespace std;
#define X first 
#define Y second 
#define MAX 301
int board[MAX][MAX];
int dist[MAX][MAX];
int dx[8] = {2,2,1,-1,-2,-2,-1,1};
int dy[8] = {-1,1,2,2,1,-1,-2,-2};
int T,K;
int main(void){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>T;
    while(T--){
        queue<pair<int, int>> Q;
        cin>>K;
        for(int i = 0;i < K;i++) fill(dist[i],dist[i] + K,-1);
        int a,b;
        int fa,fb;
        cin >> a >> b;
        cin >> fa >> fb;
        dist[a][b]++;
        Q.push({a,b});
        while(!Q.empty()){
            pair<int, int> cur = Q.front(); Q.pop();
            if(fa == cur.X && fb ==cur.Y){
                cout << dist[fa][fb]<<'\n';
                break;
            }
            for(int dir = 0 ;dir < 8; dir++)
            {
                int nx = cur.X + dx[dir];
                int ny = cur.Y + dy[dir];
                if(nx<0||nx>=K||ny<0||ny>=K) continue;
                if(dist[nx][ny] >= 0) continue;
                dist[nx][ny] = dist[cur.X][cur.Y] + 1;
                Q.push({nx,ny});
            }
        }
    }
}
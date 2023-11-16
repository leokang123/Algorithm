#include <bits/stdc++.h>
using namespace std;
#define MAX 200005
#define X first 
#define Y second 
int vis[MAX];
int first = 1;
int time1; 
int dx[3] = {0,1,-1}; // 가만히 있을때는 없지만 조건식 달기 까다로워서 이렇게함 
int dt[3] = {0,1,1};
int main(void){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int a, b;
    cin >> a >> b;
    queue<pair<int,int>> Q1;
    queue<pair<int,int>> Q2;
    vis[a] = 1;
    Q1.push({a,0});
    while(true){
        while(!Q1.empty()){
            pair<int,int> cur = Q1.front(); Q1.pop();
            Q2.push(cur);
            int cx = cur.X *2;
            int ct = cur.Y;
            if(cx <= b){
                if(vis[cx] != 0 ) continue;
                vis[cx] = 1;
                Q2.push({cx,ct});
                Q1.push({cx,ct});
            }
        }
        
        while(!Q2.empty()){
            pair<int,int> cur = Q2.front(); Q2.pop();
            for(int dir = 0;dir < 3; dir++){
                int nx = cur.X + dx[dir];
                int nt = cur.Y  + dt[dir];
                // cout << nx<<','<<nt << '\n';
                if(first && nx == b){
                    cout << nt <<'\n';
                    first = 0;
                    return 0;
                }
                if(vis[nx] != 0) continue;
                if(nx < 0 || nx >= MAX) continue;
                vis[nx] = 1;
                Q1.push({nx,nt});
            }
        }
    }
}
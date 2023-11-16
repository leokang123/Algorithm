#include <bits/stdc++.h>
using namespace std;
#define MAX 200005
#define X first 
#define Y second 
int vis[MAX];
int first;
int dx[2] = {1,-1}; 
int main(void){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    first = 1;
    int a, b;
    cin >> a >> b;
    queue<pair<int,int>> Q1;
    queue<pair<int,int>> Q2;
    vis[a] = 1;
    Q1.push({a,0});
    while(true){
        // cout << '\n';
        while(!Q1.empty()){
            pair<int,int> cur = Q1.front(); Q1.pop();
            // cout << cur.X << ','<<cur.Y<<'\n';
            if(first && cur.X == b){
                cout << cur.Y <<'\n';
                first = 0;
                break;
            }
            Q2.push(cur);
            int cx = cur.X;
            int ct = cur.Y;
            if(cx != 0 && cx <= b){
                cx = cx * 2;
                if(vis[cx] != 0 ) continue;
                vis[cx] = 1;
                Q2.push({cx,ct});
                Q1.push({cx,ct});
            }
        }
        int a = 0;
        a++;
        while(!Q2.empty()){
            pair<int,int> cur = Q2.front(); Q2.pop();
            for(int dir = 0;dir < 2; dir++){
                int nx = cur.X + dx[dir];
                int nt = cur.Y  + 1;
                if(vis[nx] != 0) continue;
                if(nx < 0 || nx >= MAX) continue;
                vis[nx] = 1;
                Q1.push({nx,nt});
            }
        }
        if(!first) break;
    }
}
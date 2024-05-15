#include <bits/stdc++.h>
using namespace std;

#define MAX 100001
#define X first 
#define Y second 

int vis[MAX * 2];

int main (void) {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int result = MAX, cnt = 0;
    int n, m; cin >> n >> m;
    queue<pair<int, int>> Q;
    Q.push({n,0});
    while(!Q.empty()) {
        pair<int, int> cur = Q.front(); Q.pop();
        vis[cur.X] = 1;
        if (cur.Y > result) continue;
        if(cur.X == m) {
            result = cur.Y;
            cnt++;
            // continue;
        }
        for(int nx : {cur.X-1, cur.X+1, cur.X * 2}) {
            if (nx < 0 || nx >= MAX * 2) continue;
            if(vis[nx]) continue;
            Q.push({nx,cur.Y + 1});
        }
    }
    cout << result << '\n';
    cout << cnt << '\n';
    return 0;
}
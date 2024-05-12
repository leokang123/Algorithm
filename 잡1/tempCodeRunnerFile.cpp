#include <bits/stdc++.h>
using namespace std;
#define MAX 1001
#define VAL 210000000
int board[MAX][MAX];
int vis[MAX];
int dist[MAX];
    int n, m;

int getMinNode(int k) {
    float min1 = VAL ;
    int index = -1;
    for(int i = 1 ; i <= n ; i++) {
        if(vis[i]) continue;
        if(min1 > board[k][i]){
            min1= board[k][i];
            index = i;
        }
    }
    return index;
}

int dfs (int k) {
    int cur = k;
    int minNode, minValue;
    for(int i = 1 ; i <= n ; i++) {
        if(board[cur][i] == VAL || cur == i) continue;
        minNode = getMinNode(cur);
        // cout << k <<' ' << minNode << '\n';
        if(minNode == -1) continue;
        minValue = min(dist[minNode], dist[cur] + board[cur][minNode]);
        dist[minNode] = minValue;
        vis[minNode] = 1;
        dfs(minNode);

    }
    return 0;
}
int main (void) {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int s, d, minValue;
    cin >> n;
    cin >> m;
    for(int i = 0 ; i <= n ; i++) fill(board[i], board[i] + n+1, VAL);
    while(m--){
        int a, b;
        cin >> a >> b;
        cin >> board[a][b];
    }
    cin >> s >> d;
    for(int i = 1 ; i <= n ; i++) {
        dist[i] = board[s][i];
    }
    dist[s] = 0;
    vis[s] = 1;
    dfs(s);
    // for(int i = 1 ; i <= n ; i++) cout << dist[i] << ' ';
    cout << dist[d] << '\n';
}
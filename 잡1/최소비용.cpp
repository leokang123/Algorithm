#include <bits/stdc++.h>
using namespace std;
#define MAX 1001
#define VAL 210000000
int board[MAX][MAX];
int vis[MAX];
int dist[MAX];
int n, m;
int getMin() {
    int min = VAL, index = -1;
    for(int i = 1 ; i <= n ; i++) {
        if(vis[i]) continue;
        if(min > dist[i]) {
            min = dist[i];
            index = i;
        }
    }
    vis[index] = 1;
    return index;
}

int dijkstra(int k) {
    int minNode = getMin();
    if(minNode == -1) return 0;
    for(int i = 1; i <= n ; i++) {
        if(vis[i]) continue;
        // 이 조건은 굳이 없어도 되긴함 (어차피 min값을 구하는거라 쓸데없는 연산을 할뿐임 안적으면) 
        if(board[minNode][i] == VAL) continue;
        dist[i] = min(dist[i], dist[minNode] + board[minNode][i]);
    }
    dijkstra(minNode);
    return 0;
}

int main (void) {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int s, d;
    cin >> n;
    cin >> m;
    for(int i = 0 ; i <= n ; i++) fill(board[i], board[i] + n+1, VAL);
    while(m--){
        int a, b, c;
        cin >> a >> b;
        cin >> c;
        if(board[a][b] != VAL && board[a][b] < c) continue;
        board[a][b] = c;
    }
    cin >> s >> d;
    vis[s] = 1;
    for(int i = 1 ; i <= n ; i++) {
        dist[i] = board[s][i];
    }
    dijkstra(s);
    dist[s] = 0;
    cout << dist[d] << '\n';
}
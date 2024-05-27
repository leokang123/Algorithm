#include <bits/stdc++.h>
using namespace std;
#define MAX 10001
int n, m, x;
vector<pair<int,int>> v[MAX];
int vis[MAX];
struct cmp {
    bool operator() (pair<int,int> a, pair<int,int> b){
        return a.second > b.second;
    }
};
int dijstra (int st, int ed) {
    fill(vis, vis + n+1, 0);
    priority_queue<pair<int,int>, vector<pair<int,int>>, cmp> pq;
    pq.push({st,0});
    while(!pq.empty()) {
        auto [node, weight] = pq.top(); pq.pop();
        if(st == ed) continue;
        if(node == ed) {
            return weight;
        }
        if(vis[node]) continue;
        vis[node] = 1;
        for(auto [nx, nw] : v[node]){
            if(vis[nx]) continue;
            pq.push({nx, nw + weight});
        }
    }
    return -1;
}
int main (void) {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cin >> n >> m >> x;
    for(int i = 0 ; i < m ; i++){
        int a, b, c;
        cin >> a >> b >> c;
        v[a].push_back({b,c});
    }
    int max1 = 0;
    for(int i = 1 ; i <= n ; i++) {
        // cout << i << "->" << x << ": ";
        int a = dijstra(i,x);
        // cout << a << ' ';
        a += (a != -1)? dijstra(x,i) : 0;
        // cout << a << '\n';
        if(max1 < a) max1 = a;
    }
    cout << max1 << '\n';

}
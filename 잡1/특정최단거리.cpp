#include <bits/stdc++.h>
using namespace std;
#define MAX 200001
#define INF (int)2e9
int n, e;
struct cmp {
    bool operator()(pair<int,int> a, pair<int,int> b) {
        return a.second > b.second;
    }
};
vector<pair<int,int>> v[MAX];
int vis[800];
int ans = INF;


int dijstra(int st, int ed) {
    fill(vis,vis+n + 1,0);
    priority_queue<pair<int,int>, vector<pair<int,int>>, cmp> pq;
    pq.push({st,0});
    while(!pq.empty()) {
        auto [node, w] = pq.top(); pq.pop();
        if(node == ed) {
            if(ans== INF) ans = w;
            else ans += w;
            return 0;
        }   
        if(vis[node]) continue;
        vis[node] = 1;
        for(auto [nx,nw] : v[node]) {
            if(vis[nx]) continue;
            pq.push({nx,nw+w});
        }
    }
    return 1;
}


int main (void) {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cin >> n >> e;
    for(int i = 0 ; i < e ; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        v[a].push_back({b,c});
        v[b].push_back({a,c});
    }
    int p1, p2; cin >> p1 >> p2;
    int min1 = ans;
    int p1_to_p2 = dijstra(p1,p2);
    int p1Val = ans;
    if(!dijstra(1,p1) && !p1_to_p2 && !dijstra(p2,n)){
        min1 = ans;
    }
    ans = INF;
    if(!dijstra(1,p2) && !p1_to_p2 && !dijstra(p1,n)){
        min1 = min(min1,ans + p1Val);
    }

    if(min1 != INF) cout << min1 << '\n';
    else cout << -1 << '\n';

}
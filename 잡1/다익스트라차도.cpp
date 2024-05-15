#include <bits/stdc++.h>
using namespace std;
#define INF (long long)1e15
#define MAX 200001
typedef long long ll ;
int n, k, x, y;
vector<tuple<int,ll,int>> v[MAX];
ll dist[MAX];
int main(void) {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    priority_queue<tuple<int,ll,int>, vector<tuple<int,ll,int>>, greater<tuple<int,ll,int>>> pq;
    cin >> n >> k >> x >> y;
    fill(dist, dist + n + 1 , INF);
    for(int i = 0 ; i < x ; i++) {
        int a, c; 
        ll b;
        cin >> a >> b >> c;
        v[a].push_back({b,c,0});
        v[b].push_back({a,c,0});
    }
    for(int i = 0 ; i < y ; i++) {
        int a, c; 
        ll b;
        cin >> a >> b >> c;
        v[a].push_back({b,c,1});
        v[b].push_back({a,c,1});
    }
    dist[1] = 0;
    pq.push({1,0,0});
    ll min1 = INF;
    while(!pq.empty()) {
        auto [X,Y,Z] = pq.top();pq.pop();
        if(Y > dist[X]) continue;
        for(int i = 0 ; i < v[X].size() ; i++) {
            auto [V,W,isroad] = v[X][i];
            
            if(isroad && Y < k) Y = k;
            if((long long)(Y + W) < dist[V]) {
                dist[V] = W + Y;
                pq.push({V,W + Y, 0});
            }
        }
    }
    cout << dist[n] << '\n';
}
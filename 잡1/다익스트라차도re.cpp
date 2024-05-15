#include <bits/stdc++.h>
using namespace std;
#define INF (long long)1e15
#define MAX 200001
typedef long long ll ;
int n, k, x, y;
vector<pair<int,ll>> v1[MAX];
vector<pair<int,ll>> v2[MAX];
int vis[MAX];
struct cmp {
    bool operator()(pair<int,int> a, pair<int,int> b) {
        // greater 왜 같은 효과(second를 특정)
        return a.second > b.second;
    }
};
int main(void) {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    priority_queue<pair<int,ll>, vector<pair<int,ll>>, cmp> pq;
    cin >> n >> k >> x >> y;
    for(int i = 0 ; i < x ; i++) {
        int a, c; 
        ll b;
        cin >> a >> b >> c;
        v1[a].push_back({b,c});
        v1[b].push_back({a,c});
    }
    for(int i = 0 ; i < y ; i++) {
        int a, c; 
        ll b;
        cin >> a >> b >> c;
        v2[a].push_back({b,c});
        v2[b].push_back({a,c});
    }
    pq.push({1,0});

    // 이런 방식이 되는 이유는 어차피 pq 는 최소거리로 정렬하기 때문에 적절하지 않은 것들을 다 pq에 넣어도 
    // pq에서 뽑는 순간 vis[X] = 1 처리를 해주기 떄문에 따로 엉둥한 노드에 방문하지 않는다 
    // 원래같으면 배열하나를 두고 비교하면서 진행해야하는데 이방법의 경우 모든 노드로의 최소거리를 구하는것이 아니고 
    // 1에서 n까지의 최소시간이므로 이렇게 배열없이 진행해도 상관없다 
    while(!pq.empty()) {
        auto [X,Y] = pq.top();pq.pop();
        if(vis[X]) continue;
        vis[X] = 1;
        if(X == n) {
            cout << Y << '\n';
            return 0;
        }
        for(auto a : v1[X]) {
            int V = a.first;
            ll W = a.second + Y;
            if(vis[V]) continue;
            pq.push({V,W});
        }

        for(auto a : v2[X]) {
            int V = a.first;
            ll W = max(Y,(ll)k) + a.second;
            if(vis[V]) continue;
            pq.push({V,W});
        }
    }
    // cout << dist[n] << '\n';
}
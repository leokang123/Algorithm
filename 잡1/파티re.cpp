/*
    우리가 보통 아는 다익스트라 는 one to all 방식인데 
    이것을 조금 변형하면 all to one 최단경로를 구할수 있다 
    그냥 방향그래프의 방향을 거꾸로 뒤집고 똑같이 계산해주면 된다 
*/

#include <bits/stdc++.h>

using namespace std;
#define MAX 10001
#define INF (int) 1e9
int n, m, x;
int dist[2][MAX];
vector<pair<int,int>> v[2][MAX];

struct cmp {
    bool operator() (pair<int,int> a, pair<int,int> b){
        return a.second > b.second;
    }
};
void dijstra (int st, int ver) {
    priority_queue<pair<int,int>, vector<pair<int,int>>, cmp> pq;
    pq.push({st,0});
    while(!pq.empty()) {
        auto [node, weight] = pq.top(); pq.pop();
        if(dist[ver][node] < weight) continue;
        dist[ver][node] = weight;
        for(auto [nx, nw] : v[ver][node]){
            if(dist[ver][nx] > nw + weight) pq.push({nx, nw + weight});
        }
    }
}
int main (void) {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cin >> n >> m >> x;
    for(int i = 0 ; i < 2 ; i++) fill(dist[i], dist[i] + n + 1, INF);
    for(int i = 0 ; i < m ; i++){
        int a, b, c;
        cin >> a >> b >> c;
        v[0][a].push_back({b,c});
        v[1][b].push_back({a,c});
    }
    int max1 = 0;
    dijstra(x,0);
    dijstra(x,1);
    for(int i = 1; i <= n ; i++) {
        dist[0][i] += dist[1][i];
        max1 = max(max1, dist[0][i]);
    }

    cout << max1 << '\n';

}
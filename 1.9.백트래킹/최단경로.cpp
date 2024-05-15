#include <bits/stdc++.h>
using namespace std;
#define MAX 20001
#define INF 1e9 // 10억 

vector<pair<int, int>> v[MAX];
// less는 오름차순 -> top하면 큰값이 먼저나옴, greater는 내림차순 -> top하면 작은값이 먼저나옴 
priority_queue<pair<int, int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
int dist[MAX];
int n, m; 


int main (void) {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cin >> n >> m;
    int start; cin >> start;
    fill(dist, dist+ n+1, INF);
    while(m--) {
        int a,b,c;cin >> a >> b >> c;
        v[a].push_back({b,c});
    }
    dist[start] = 0;
    pq.push({0,start});
    while(!pq.empty()) {
        // 최솟값을 뽑는 과정 
        pair<int, int> cur = pq.top(); pq.pop();
        // U까지 최소비용
        int X = cur.first;
        int U = cur.second;
        if (dist[U] < X) continue;
        for(int i = 0 ; i < v[U].size(); i++) {
            // U에서 시작하는 간선들을 반대편 노드를 V에 담는다 
            int V = v[U][i].first;
            // U에서 시작하는 간선의 가중치를 W에 담는다 
            int W = v[U][i].second;

            if(X + W < dist[V]) {
                dist[V] = X + W;
                pq.push({X+W, V});
            }
        }
    }

    for(int i = 1 ; i <= n ; i++){
        if(dist[i] == INF) {
            cout << "INF" << '\n';
            continue;
        }
        cout << dist[i] << '\n';
    }
    return 0;
}
#include <bits/stdc++.h>
using namespace std;
#define MAX 1001
#define INF 1e9

#define X first
#define Y second 
int dist[MAX];

int main (void) {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    vector<pair<int, int>> v[MAX];
    priority_queue<pair<int, int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    int n, m, sc, dst;
    cin >> n;
    cin >> m;
    fill(dist, dist + n + 1, INF);
    while (m--) {
        int a, b, c;
        cin >> a >> b >> c;
        v[a].push_back({b,c});
    }
    cin >> sc >> dst;
    pq.push({sc, 0});
    while(!pq.empty()) {
        pair<int,int> cur = pq.top(); pq.pop();

        // 같을때도 continue해도 될거같은기분이지만, 같을땐 continue해주면안된다 
        // (같을때가 하나의 간선만으로 이동하는 경우일 가능성이있어서.. )
        if (cur.Y > dist[cur.X]) continue;
        for(int i = 0 ; i < v[cur.X].size(); i++) {
            int vertice = v[cur.X][i].X;
            int weight = v[cur.X][i].Y;

            if(cur.Y + weight < dist[vertice]) {
                dist[vertice] = cur.Y + weight;
                pq.push({vertice, cur.Y + weight});
            }
        }
    }
    cout << dist[dst] <<'\n';
    return 0;
}
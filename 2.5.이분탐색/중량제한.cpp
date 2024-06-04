#include <bits/stdc++.h>
using namespace std;

int st, ed;
vector<pair<int, int>> arr[200002];

int BFS(int k) {
    int check[10001] = {0,};
    queue<int> q; 
    check[st] = 1;
    q.push(st);
    while (!q.empty()) {
        int cur = q.front(); q.pop();
        for(auto [nx, nw] : arr[cur]) {
            if (check[nx] || k > nw ) continue;
            if (nx == ed ) return 0;
            check[nx] = 1;
            q.push(nx);
        }
    }
    return 1;
}

int main (void) {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n, m; cin >> n >> m ;
    int high = 0, low = 0;
    for(int i = 0 ; i < m ; i++) {
        int a, b, c; cin >> a >> b >> c;
        arr[a].push_back({b,c});
        arr[b].push_back({a,c});
        high = max(high, c);
    }  
    cin >> st >> ed;
    high++;
    while (high > low + 1) {
        int mid = (high + low) / 2;
        // 가능해? 좀 더 중량 높혀서 다시 해봐 
        if(!BFS(mid)) low = mid;
        // 가능하지 않네? 좀 낮혀서 다시 해봐 
        else high = mid;
    }
    cout << low << '\n';
}
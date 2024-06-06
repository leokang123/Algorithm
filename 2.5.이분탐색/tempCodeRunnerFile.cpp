#include <bits/stdc++.h>
using namespace std;

int main (void) {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n, m; cin >> n >> m ;
    vector<int> oven(n);
    vector<int> pizza(m);
    for(auto& i: oven) cin >> i;
    for(auto& i: pizza) cin >> i;
    int ed = 0, p = 0;
    while (p < n && oven[p] >= pizza[0]) p++;
    ed = --p;p--;
    for(int i = 1; i < m ; i++) {
        while (p > 0 && oven[p] < pizza[i]) p--;
        ed = p--;
    }
    ed + 1 <= 0 ? ed = 0 : ed = ed + 1;
    cout << ed << '\n';
    return 0;
}
#include <bits/stdc++.h>
using namespace std;

bool compare(pair<int,int> a, pair<int,int>b) {
    if(a.second == b.second) return a.first < b.first; 
    return a.second < b.second;
}
vector<pair<int, int>> v;
int main(void) {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int n; cin >> n;
    for(int i = 0 ; i < n ; i++) {
        int a,b; cin >> a >> b;
        v.push_back({a,b});
    }
    sort(v.begin(), v.end(), compare);
    // for(auto [a,b] : v) cout << a << ' '<< b << '\n';
    int cnt = 1;
    auto [st, ed] = v[0];
    for(int j = 1 ; j < n ; j++) {
        auto [nt, nd] = v[j];
        if (ed > nt) continue;
        cnt++;
        ed = nd;
    }
    cout << cnt << '\n';
    return 0;
}
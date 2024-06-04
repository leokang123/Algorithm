#include <bits/stdc++.h>
using namespace std;

vector<pair<int, int>> v;
int main(void) {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int n; cin >> n;
    for(int i = 0 ; i < n ; i++) {
        int a,b; cin >> a >> b;
        v.push_back({a,b});
    }
    sort(v.begin(), v.end());
    auto [st, ed] = v[0];
    int length = 0;
    for(int j = 1 ; j < n ; j++) {
        auto [nt, nd] = v[j];
        if (ed > nt) {
            ed = max(ed, nd);
            continue;
        }
        length += ed - st;
        st = nt;
        ed = nd;
    }
    length += ed - st;
    cout << length << '\n';
    return 0;
}
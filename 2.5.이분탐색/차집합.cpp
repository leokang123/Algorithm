#include <bits/stdc++.h>
using namespace std;

int main (void) {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int n, m;
    cin >> n >> m;
    vector<int> v1(n);
    for(auto & i : v1) cin >> i;
    vector<int> v2(m);
    vector<int> v3;
    for(auto & i : v2) cin >> i;
    sort(v2.begin(), v2.end());
    for(auto i : v1) {
        int idx = lower_bound(v2.begin(), v2.end(), i) - v2.begin();
        if (idx >= m || v2[idx] != i) v3.push_back(i);
    }
    
    sort(v3.begin(), v3.end());
    cout << v3.size() << '\n';
    for(int i : v3) cout << i << ' ' ;
}
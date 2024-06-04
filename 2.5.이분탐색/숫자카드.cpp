#include <bits/stdc++.h>
using namespace std;

int main (void) {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n; cin >> n;
    vector<int> my(n);
    for(auto& i : my) cin >> i;
    sort(my.begin(), my.end());
    int m; cin >> m;
    for (int i = 0 ; i < m ; i++) {
        int a ; cin >> a; 
        int idx = lower_bound(my.begin(), my.end(), a) - my.begin();
        if (idx >= n || a != my[idx]) {
            cout << 0 << ' ';
            continue;
        }
        cout << 1 << ' ';
    }
    return 0;
}
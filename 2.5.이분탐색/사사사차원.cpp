#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main (void) {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n, m; cin >> n >> m;
    vector<ll> candy(m);
    cin >> candy[0];
    for(int i = 1 ; i < m ; i++) {
        ll a ; cin >> a;
        candy[i] += candy[i-1] + a;
    }
    for(int i = 1 ; i <= n ; i++) {
        ll a ; cin >> a;
        int idx = lower_bound(candy.begin(), candy.end(), a) - candy.begin();
        if(idx < m) cout << idx+1 << '\n';
        else cout << "Go away!" << '\n';
    }
    return 0;
}
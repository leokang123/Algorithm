#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main (void) {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int n, m; cin >> n >> m;
    vector <ll> arr(m);
    ll sum = 0;
    for(auto& i: arr) {
        cin >> i;
        sum += i;
    }
    sort(arr.begin(), arr.end());
    ll candy = sum - n;
    ll ans = 0;
    for(auto i : arr) {
        ll k = min(i, candy/m--);
        ans += k * k;
        candy -= k;
    }
    cout << ans << '\n';
    return 0;
}
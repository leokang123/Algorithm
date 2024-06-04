#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main (void) {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int m, n; cin >> m >> n;
    vector<ll> arr(m);
    for (auto& i: arr) cin >> i;
    sort(arr.begin(), arr.end());
    ll low = 0;
    ll high = arr[0] * n + 1;
    while(high > low + 1) {
        ll mid = (high + low) / 2;
        ll cnt = 0;
        for(auto i : arr) cnt += mid / i;
        cnt >= n ? high = mid : low = mid;
    }
    cout << high << '\n';
}
#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n; cin >> n;
    vector<int> v(n);
    for(auto& i : v) cin >> i;

    vector<int> cnt(100001);
    int j = 0;
    long long ans = 0;
    for(int i = 0 ; i < n ; i++) {
        cnt[v[i]]++;
        while(j < i && cnt[v[i]] >= 2) {
            cnt[v[j]]--;
            j++;
        }
        ans += i - j + 1;
    }
    cout << ans << '\n';
}

int main (void) {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    solve();
}
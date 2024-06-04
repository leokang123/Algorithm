#include <bits/stdc++.h>
using namespace std;

int main (void) {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n, k; cin >> n >> k;
    vector<int> arr(k);
    int high = 0, low = 0;
    for (auto& i: arr) {
        cin >> i;
        high = max(high,i);
    }
    high++;
    int cnt = 0;
    while (high > low + 1) {
        cnt = 0;
        int mid = (high + low) / 2;
        for(auto i : arr) cnt += i / mid;
        if(cnt >= n) low = mid;
        else high = mid;
    }
    cout << low << '\n';
    return 0;
}
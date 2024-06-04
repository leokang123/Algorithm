#include <bits/stdc++.h>
using namespace std;

int main (void) {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n, k; cin >> n >> k;
    vector<int> arr(n);
    for(auto& i: arr) cin >> i;
    sort(arr.begin(), arr.end());

    int high = arr[n-1] + 1;
    int low = -1;
    long long ans = 0;
    while (high > low + 1) {
        int mid = (high + low) / 2;
        ans = 0;
        for(auto i : arr) {
            ans += (i - mid >= 0)? i - mid : 0;
        }
        if(ans >= k) low = mid;
        else high = mid;
    }
    cout << low << '\n';

}
#include <bits/stdc++.h>
using namespace std;

int main (void) {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n, k; cin >> n >> k;
    vector<int> arr(n);
    for(auto& i : arr) cin >> i;
    sort(arr.begin(), arr.end());
    int low = 0;
    int high = arr[n-1] + 1;
    while (high > low + 1) {
        int mid = (high + low) / 2;
        int cnt = 1, last = 0;
        for(int i = 1 ; i < n ; i++) 
            if(arr[i] - arr[last] >= mid) {
                cnt++;
                last = i;
            }
        cnt >= k ? low = mid : high = mid;
    }
    cout << low << '\n';
    return 0;
}
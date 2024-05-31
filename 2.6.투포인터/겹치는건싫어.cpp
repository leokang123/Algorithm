#include <bits/stdc++.h>
using namespace std;

int main (void) {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int n, k; cin >> n >> k;
    vector<int> arr(n);
    vector<int> cnt(100001);
    for (auto& i : arr) cin >> i;
    int j = 0;
    int max1 = 0;
    for (int i = 0 ; i < n ; i++) {
        cnt[arr[i]]++;
        while(j < i && cnt[arr[i]] > k) {
            cnt[arr[j]]--;
            j++;
        }
        max1 = max(max1, i - j + 1);
    }
    cout << max1 << '\n';
}
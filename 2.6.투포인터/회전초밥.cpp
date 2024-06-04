#include <bits/stdc++.h>
using namespace std;

int main (void) {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n, d, k, c; cin >> n >> d >> k >> c;
    vector<int> arr(n);
    vector<int> cnt(30001);
    for (auto& i : arr) cin >> i;
    int left = 0, right = 0;
    int count = 0;
    int ans = 0;
    int fin = 0;
    while(left <= right && left < n) {
        while(right - left + 1 <= k) {
            cnt[arr[(right+n) % n]]++;
            if (cnt[arr[(right+n) % n]] == 1) count++;
            if (right - left + 1 == k) {
                if (count == k && cnt[c] == 0) {
                    fin = 1;
                    ans = count + 1;
                }
                right++;
                break;
            }
            right++;
        }
        if (fin) break;
        if (ans <= count) {
            ans = min(k,count);
            if (cnt[c] == 0) ans += 1;
        }
        cnt[arr[left]]--;
        if (cnt[arr[left]] == 0) count--;
        left++;
    }

    cout << ans << '\n';

}
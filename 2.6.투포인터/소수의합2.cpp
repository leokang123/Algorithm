#include <bits/stdc++.h>
using namespace std;

bool notprime[4000001];
long long psum[2000002];

int main (void) {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n; cin >> n;
    int k = 0;
    for(long long i = 2; i <= n; i++) {
        if (!notprime[i]) {
            k++;
            psum[k] = psum[k-1] + i;
            for (long long j = i*i; j <= n; j+=i) notprime[j] = 1;
        }
    }
    int cnt = 0;
    int left = 0, right = 1;
    while (right <= k) {
        while (psum[right] - psum[left] >= n) {
            if (psum[right] - psum[left] == n) cnt++;
            left++;
        }
        right++;
    }
    cout << cnt << '\n';
    return 0;
}

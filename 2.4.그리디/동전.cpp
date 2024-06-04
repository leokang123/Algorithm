#include <bits/stdc++.h>
using namespace std;

int coins[10];
int main(void) {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int n, k; cin >> n >> k;
    int cnt = 0;
    for(int i = 0 ; i < n ; i++) cin >> coins[i];
    for(int i = n-1 ; i >= 0 ; i--) {
        if((k / coins[i] )== 0) continue;
        cnt += k / coins[i];
        k = k % coins[i];
    }
    cout << cnt << '\n';

    return 0;
}
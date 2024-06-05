#include <bits/stdc++.h>
using namespace std;

int board[2];

int main (void) {
    cin.tie(nullptr)->sync_with_stdio(false);
    int miss, n; 
    while(cin >> miss >> n) {
        bool isfound = 0;
        miss = miss * (int)1e7;
        vector<int> lego(n);
        for (auto& i: lego) cin >> i;
        sort(lego.begin(), lego.end());
        for (int i = 0 ; i < n ; i++) {
            int key = miss - lego[i];
            // 자신을 제외한 범위에서 탐색 
            // 열린구간 탐색 (i,n)
            int low = i;
            int high = n;
            while(high > low +1) {
                int mid = (high + low) / 2;
                lego[mid] >= key ? high = mid : low = mid;
            }
            // int idx = lower_bound(lego.begin() + i + 1, lego.end(), key) - lego.begin();
            int idx = high;
            if (idx >= n || idx < 0) continue;
            if (lego[idx] + lego[i] == miss) {
                isfound = 1;
                board[0] = lego[i];
                board[1] = lego[idx];
                break;
            }
        }
        if (isfound) cout << "yes" << ' ' << board[0] << ' ' << board[1] << '\n';
        else cout << "danger"<< '\n';
    }
    return 0;
}
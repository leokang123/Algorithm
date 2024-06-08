#include <bits/stdc++.h>
using namespace std;

int main (void) {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n; cin >> n;
    vector<int> arr(n);
    int sum = 0;
    int max1 = 0;
    for (auto& i: arr) {
        cin >> i;
        sum += i;
        max1 = max(max1,i);
    }
    int m; cin >> m;
    if(sum <= m) {
        cout << max1 << '\n';
        return 0;
    }
    int high = 100001;
    int low = 0;
    while (high > low + 1) {
        int mid = (high + low) / 2;
        int cnt = 0;
        for(auto i : arr) cnt += min(i, mid);

        cnt > m ? high = mid : low = mid;
    }
    cout << low << '\n';
    return 0;

}
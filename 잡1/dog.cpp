#include <bits/stdc++.h>
using namespace std;

int main (void) {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int n; cin >> n;

    while(n--) {
        int cnt = 0;
        int m ; cin >> m;
        vector<int> interval(m);
        cin >> interval[0];
        if (interval[0] >= 120) cnt += interval[0] / 120;
        for(int i = 1 ; i < m ; i++) {
            cin >> interval[i];
            if(interval[i] - interval[i-1] >= 120) cnt += (interval[i] - interval[i-1]) / 120;
        }
        if (1439 - interval[m-1] >= 120) cnt += (1439 - interval[m-1]) / 120;
        cnt >= 2 ? cout << "YES" : cout << "NO";
        cout << '\n';
    }
}
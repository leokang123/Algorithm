#include <bits/stdc++.h>
using namespace std;

int main (void) {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n, m; cin >> n >> m ;
    vector<int> oven(n);
    vector<int> pizza(m);
    for(int i = 0 ; i < n ; i++) {
        cin >> oven[i];
        if(i > 0 && oven[i-1] < oven[i]) oven[i] = oven[i-1];
    }
    for(auto& i: pizza) cin >> i;
    int high = n+1, low = -1;
    int cnt = 0;
    for(int i = 0 ; i < m ; i++) {
        while(high > low + 1) {
            int mid = (high + low) / 2;
            if (oven[mid] >= pizza[i]) low = mid;
            else high = mid;
        }
        if(oven[low] >= pizza[i]) cnt++;
        high = low;
        low = -1;
    }
    cnt == m ? cout << high+1 << '\n' : cout << 0 << '\n';
    return 0;
}
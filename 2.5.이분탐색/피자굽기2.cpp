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
    int p = -1, cnt =0, ans = 0;
    while(p < n-1 && oven[p+1] >= pizza[0]) p++;
    if(p > -1) {
        cnt++;
        p--;
    }
    for(int i = 1 ; i < m; i++) {
        while(p > -1 && oven[p] < pizza[i]) p--;
        if(p > -1) {
            cnt++;
            ans = p;
            p--;
        }
    }
    cnt == m ? ans++ : ans = 0;
    cout << ans << '\n';
    return 0;
}
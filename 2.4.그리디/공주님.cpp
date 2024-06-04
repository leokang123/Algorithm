#include <bits/stdc++.h>
using namespace std;

int main (void) {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    vector<pair<int,int>> v;
    int n ; cin >> n ;
    for(int i = 0 ; i < n ; i++) {
        int a,b,c,d; cin >> a >> b >> c >> d;
        v.push_back({a*100 + b, c * 100 + d});
    }
    sort(v.begin(),v.end());
    auto [st,ed] = v[0];
    int min1 = st;
    int max1 = ed; 
    int cnt = 1;
    for(int i = 1 ; i < n ; i++) {
        auto [nt,nd] = v[i];
        max1 = max(max1, nd);
        if(ed >= 1201) break;
        if (nd <= 301) continue;
        if(nt <= 301 && nd > ed) {
            st = nt;
            ed = nd;
            continue;
        }
        if (st >= nt) {
            ed = max(ed,nd);
            continue;
        }
        if (ed >= nt && nd > ed) {
            st = ed;
            ed = max(nd,ed);
            cnt++;
        }
        if(ed < nt) {
            cnt = 0 ;
            break;
        }
    }
    if(min1 > 301 || max1 <1201) cnt = 0;
    cout << cnt << '\n';

    return 0;
}
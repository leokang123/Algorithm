#include <bits/stdc++.h>
using namespace std;

int main (void) {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    vector<int> v;
    int zero_and_minus = 0;
    int n; cin >> n;
    for(int i = 0 ; i < n ; i++) {
        int a ; cin >> a;
        if(a <= 0) zero_and_minus++;
        v.push_back(a);
    }
    sort(v.begin(), v.end());
    int res = 0;
    int init_zm = zero_and_minus; // 3
    for(int i = 0 ; i < init_zm ; i+=2) {
        if(i == init_zm -1) {
            res += v[i];
            continue;
        }
        res += v[i] * v[i+1];
        zero_and_minus -= 2;
    }
    for(int i = n-1 ; i >= init_zm ; i -= 2) {
        if(i == init_zm) {
            res += v[i];
            continue;
        }
        if(v[i-1] == 1) {
            res += v[i] + v[i-1];
            continue;
        }
        res += v[i] * v[i-1];
    }
    cout << res << '\n';
    return 0;
}   
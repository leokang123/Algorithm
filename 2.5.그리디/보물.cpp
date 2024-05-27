#include <bits/stdc++.h>
using namespace std;

int main(void) {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int n; cin >> n;
    vector <int> v1, v2;
    for(int i = 0 ; i < n; i++) {
        int a; cin >> a;
        v1.push_back(a);
    }
    for(int i = 0 ; i < n; i++) {
        int a; cin >> a;
        v2.push_back(a);
    }
    sort(v1.begin(), v1.end());
    sort(v2.begin(), v2.end(), greater<int>());
    int res = 0;
    for(int i = 0 ; i < n ; i++) {
        res += v1[i] * v2[i];
    }
    cout << res << '\n';
}
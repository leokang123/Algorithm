#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n ; cin >> n ;
    vector<int> arr(n);
    vector<int> check(100001);
    for(auto& i : arr) cin >> i;
    int j = 1;  
    long long res = 0;
    for(int i = 0 ; i < n ; i++) {
        check[arr[i]] = 1;
        if(i == j) j++;
        while (j < n && check[arr[j]] == 0) {
            check[arr[j]] = 1;
            j++;
        }
        res += j - i ;
        check[arr[i]] = 0;
    }
    cout << res << '\n';
}

int main (void) {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    solve();
}
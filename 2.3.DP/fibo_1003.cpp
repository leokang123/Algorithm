#include <bits/stdc++.h>
using namespace std;

int memo[41][2];

int main (void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    memo[0][0] = 1;
    memo[0][1] = 0;
    memo[1][0] = 0;
    memo[1][1] = 1;
    int T; cin >> T;
    for (int i = 2 ; i <= 40; i++) {
        memo[i][0] = memo[i-1][0] + memo[i-2][0];
        memo[i][1] = memo[i-1][1] + memo[i-2][1];
    }
    while(T--) {
        int a; cin>> a;
        cout << memo[a][0] << ' ' << memo[a][1] <<'\n';
    }
    
}
// red : 0, green : 1, blue : 2
#include <bits/stdc++.h> 
using namespace std;

int memo[1001][3];
int cost[1001][3];

int main (void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; cin >> n;
    for(int i = 0 ; i < n; i++) {
        for(int j = 0 ; j < 3; j++) cin >> cost[i][j];
    }
    memo[0][0] = cost[0][0];
    memo[0][1] = cost[0][1];
    memo[0][2] = cost[0][2];
    for (int i = 1 ; i < n ; i++) {
        memo[i][0] = min(memo[i-1][1],memo[i-1][2]) + cost[i][0];
        memo[i][1] = min(memo[i-1][0],memo[i-1][2]) + cost[i][1];
        memo[i][2] = min(memo[i-1][1],memo[i-1][0]) + cost[i][2];
    }
    cout << min({memo[n-1][0],memo[n-1][1],memo[n-1][2]}) << '\n';
}
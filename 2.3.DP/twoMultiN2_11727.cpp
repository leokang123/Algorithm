#include <bits/stdc++.h> 
using namespace std;

int memo[1001];

int main (void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N; cin >> N;
    memo[1] = 1;
    memo[2] = 3;
    memo[3] = memo[2] + memo[1] * 2;
    if (N <= 3) {
        cout << memo[N] << '\n';
        return 0;
    }
    for(int i = 4; i <= N ; i++) {
        memo[i] = (memo[i-1] + memo[i-2] * 2) % 10007;
    }
    cout << memo[N] << '\n';
    return 0;
}
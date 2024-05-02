#include <bits/stdc++.h>
using namespace std;

int memo[100002];



int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N; cin >> N;
    int sqrt_n = sqrt(N);
    memo[1] = 1;
    memo[2] = 2;
    memo[3] = 3;
    for(int i =  1; i <= sqrt_n ; i++) memo[i*i] = 1;
    for(int i = 1; i <= N; i++) {
        if(memo[i]) continue;
        memo[i] = i;
        for(int j = 1 ; j*j <= i; j++) {
            memo[i] = min(memo[i], memo[i-j*j] + 1);
        }
    }
    cout << memo[N] << '\n';
}

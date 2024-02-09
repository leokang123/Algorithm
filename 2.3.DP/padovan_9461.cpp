#include <bits/stdc++.h>
using namespace std;

long long memo[101];

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    memo[0] = 1;
    memo[1] = 1;
    memo[2] = 1;
    memo[3] = 2;
    memo[4] = 2;
    int a = 0;
    for (int i = 5 ; i < 101 ; i++) {
        memo[i] = memo[i-1] + memo[a++];
    }

    int N ; cin >> N;
    while(N--){
        int a ; cin >> a;
        cout << memo[a-1] << '\n';
    }
}
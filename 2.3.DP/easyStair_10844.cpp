#include <bits/stdc++.h>
using namespace std;

long long memo[101][10];

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N; cin >> N;
    memo[1][0] = 0;
    for(int i = 1 ; i <= 9 ; i++) memo[1][i] = 1;

    for(int i = 2 ; i <= N ; i++){
        for(int j = 0 ; j <= 9 ; j++) {
            if (j-1 >=0) memo[i][j] += memo[i-1][j-1];
            if (j+1 <=9) memo[i][j] += memo[i-1][j+1];
            memo[i][j] = memo[i][j] % 1000000000;
        }
    }
    long long sum = 0;
    for(int i = 0 ; i < 10; i++) sum+= memo[N][i];
    sum = sum % 1000000000;
    cout << sum << '\n';
}

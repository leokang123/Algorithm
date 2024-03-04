#include <bits/stdc++.h>
using namespace std;

int memo[1001];

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n; cin >> n;
    memo[1] = 1;
    memo[2] = 2;
    for (int i = 3 ; i <= n; i++) {
        // 시작하는게 하나짜리 막대기냐, 두개짜리 누운 막대기 두개냐 
        memo[i] =(memo[i-1] + memo[i-2]) % 10007;
    }
    cout << memo[n] << '\n';
}
// 아 왜 모르겠지.. 너무 집중안하나 
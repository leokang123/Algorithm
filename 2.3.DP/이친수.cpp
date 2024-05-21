#include <bits/stdc++.h>
using namespace std;
#define MAX 92
// 먼저 범위를 생각하자 
long long check[MAX][2];

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n; cin >> n;
    check[1][0] = 0;
    check[1][1] = 1; // 1

    for(int i = 2 ; i <= n ; i++) {
        check[i][1] = check[i-1][0];
        check[i][0] = check[i-1][0] + check[i-1][1];
    }
    cout << check[n][0] + check[n][1] << '\n';
}
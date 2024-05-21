#include <bits/stdc++.h>
using namespace std;
#define MAX 1001

int check[MAX];
int main (void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; cin >> n;
    check[1] = 1;
    check[2] = 3;
    for(int i = 3; i <=n ;i++) {
        check[i] = (check[i-1] + check[i-2] * 2) % 10007;
    }
    cout << check[n] << '\n';
    return 0;
}
#include <bits/stdc++.h>
using namespace std;

int memo[100001];
int arr[100001];

int main (void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N; cin >> N;
    int M; cin >> M;
    // for(int i = 0 ; i < N; i++) {
    //     int a ; cin >> a;
    //     memo[i] += a;
    //     if(i == 0) continue;
    //     memo[i] += memo[i-1];
    // }

    for(int i = 1 ; i <= N ; i++) {
        int a ; cin >> a;
        memo[i] = memo[i-1] + a;
    }
    while(M--) {
        int i, j; cin >> i >> j;
        cout << memo[j] - memo[i-1] << '\n';
    }
    return 0;
}
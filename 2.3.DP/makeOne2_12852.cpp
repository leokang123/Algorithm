#include <bits/stdc++.h>
using namespace std;

int memo[1000001];
int extra[1000001];

int main (void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N; cin >> N;
    memo[1] = 0;
    extra[1] = 0;
    for(int i = 2; i <= N; i++) {
        memo[i] = memo[i-1] + 1;
        extra[i] = i-1;
        if(i % 2 == 0 && memo[i] > memo[i/2] + 1) {
            memo[i] = memo[i/2] + 1;
            extra[i] = i/2;
        }
        if(i % 3 == 0 && memo[i] > memo[i/3] + 1) {
            memo[i] = memo[i/3] + 1;
            extra[i] = i/3;
        }
    }
    cout << memo[N] << '\n';
    int num = N;
    // cout << num <<' ';
    // while(extra[num]) {
    //     cout << extra[num] << ' ';
    //     num = extra[num];
    // }
    while(true) {
        if(num == 0) break;
        cout << num << ' ';
        num = extra[num];
    }
    cout << '\n';
    return 0;
    
}
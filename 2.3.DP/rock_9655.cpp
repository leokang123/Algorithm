#include <bits/stdc++.h>
using namespace std;

int memo[1000];

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    memo[1] = 1; 
    memo[2] = 2;
    memo[3] = 1;
    int N ; cin >> N ;
    for(int i = 4 ; i <= N; i++) {
        memo[i] = min(memo[i-1] + 1, memo[i-3] + 1);
    }    
    if(memo[N] % 2 == 0) cout << "CY\n";
    else cout << "SK\n";
}
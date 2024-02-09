#include <bits/stdc++.h>
using namespace std;

int memo[100001];

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N; cin >> N;
    int max = -1000;
    for(int i = 0 ; i < N ; i++) {
        cin >> memo[i];
        if(max < memo[i]) max = memo[i]; // 원소중 가장 큰수 
    }
    for(int i = 1; i< N ; i++){
        if(memo[i-1] < 0 || memo[i-1] + memo[i] < 0) continue;
        memo[i] = memo[i] + memo[i-1];
        if (max <= memo[i]) max = memo[i];
    }
    cout << max << '\n';
    return 0 ;
}
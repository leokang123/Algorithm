#include <bits/stdc++.h>
using namespace std;
int memo[1000001];


int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int num; cin >> num;
    //botttom up 방식 
    for(int i = 2; i <= num; i++) {
        memo[i] = memo[i-1] + 1;
        if(i % 2 == 0) memo[i] = min(memo[i], memo[i/2] + 1);
        if(i % 3 == 0) memo[i] = min(memo[i], memo[i/3] + 1);
    }
    cout << memo[num] << '\n';
}
#include <bits/stdc++.h>
using namespace std;

int memo[1001][1001];

int main (void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s1, s2; cin >> s1 >> s2;

    for(int i = 1 ; i <= s1.length() ;i++) {
        for(int j = 1 ; j <= s2.length() ; j++) {
            if(s1[i-1] == s2[j-1]){ 
                memo[i][j] = memo[i-1][j-1] + 1;
            }
            else {
                memo[i][j] = max(memo[i-1][j], memo[i][j-1]);
            }
        }
    }
    for(int i = 0 ; i <= s1.length() ; i++) {
        for(int j = 0 ; j <= s2.length(); j++) cout << memo[i][j] <<' ';
        cout << '\n';
    }

    cout << memo[s1.length()][s2.length()] << '\n';
}
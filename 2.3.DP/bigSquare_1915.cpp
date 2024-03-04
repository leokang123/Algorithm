#include <bits/stdc++.h>
using namespace std;

int memo[1000][1000];
int board[1000][1000];
int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M ; cin >> N >> M;
    int max = 0 ;

    for(int i = 0 ; i < N ; i++) {
        for(int j = 0 ; j < M ; j++) {
            char a; cin >> a;
            if(a == '0') memo[i][j] = 0;
            if(a == '1'){
                memo[i][j] = 1;
                max = 1;
            }
        }
    }
    for(int i = 1; i < N ; i++) {
        for(int j = 1; j < M ;j++) {
            if(memo[i][j]) memo[i][j] = min({memo[i-1][j-1],memo[i-1][j],memo[i][j-1]}) + 1;
            if(max < memo[i][j]) max = memo[i][j];
        }
    }
    cout << max*max << '\n';
    // for(int i = 0 ; i < N ; i++ ){
    //     for(int j = 0 ; j < M ; j++) {
    //         cout << memo[i][j] << ' ';
    //     }
    //     cout << '\n'; 
    // }
}
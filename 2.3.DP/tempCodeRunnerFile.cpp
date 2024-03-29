#include <bits/stdc++.h>
using namespace std;

int memo[1000][1000];
int board[1000][1000];
int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M ; cin >> N >> M;
    for(int i = 0 ; i < N ; i++) {
        for(int j = 0 ; j < M ; j++) {
            char a; cin >> a;
            if(a == '0') board[i][j] = 0;
            if(a == '1') board[i][j] = 1;
        }
    }
    int max = 0 ;
    for(int i = 1; i < N ; i++) {
        for(int j = 1; j < M ;j++) {
            memo[i][j] = min({board[i-1][j-1],board[i-1][j],board[i][j-1],board[i][j]}) + 1;
            if(max < memo[i][j]) max = memo[i][j];
        }
    }
    cout << max << '\n';
}
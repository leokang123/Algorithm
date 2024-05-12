#include <bits/stdc++.h>
using namespace std;

#define MAX 51

// 구라친 파티 넘버
int board[MAX];
int notlied[MAX];
// 해당 파티에 참가한 사람 
int v[MAX][MAX];
// 사람이 참가한 파티 
int v2[MAX][MAX];
int n, m;

void erase1(int k) {
    for(int i = 1 ; i <= n; i++) {
        if (v[k][i] != 1) continue;  
        notlied[i] = 1;
        for(int j = 0 ; j < m ; j++){
            if(v2[i][j] != 1) continue;
            if (board[j] != 1) continue;
            board[j] = 0;
            erase1(j);
        }
    }
    return ;
}

int main (void) {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int knows;
    cin >> n >> m;
    cin >> knows;
    for(int i = 0 ; i < knows ; i++) {
        int a; cin >> a;
        notlied[a] = 1;
    }

    for(int i = 0 ; i < m ; i++) {
        int flag = 0;
        int num; cin >> num;
        for(int j = 0 ; j < num ; j++) {
            int a; cin >> a;
            v[i][a] = 1;
            v2[a][i] = 1;
            if (notlied[a]) {
                flag = 1;
            }
        }
        if(!flag) {
            board[i] = 1;
            continue;
        }
        for(int j = 1 ; j <= n ; j++) {
            if(v[i][j] != 1) continue;
            notlied[j] = 1;
        }
        erase1(i);
    }
    int add = 0 ;
    for(int i = 0 ; i < m ; i++) {
        add += board[i];
    }
    cout << add << '\n';
    return 0;
}
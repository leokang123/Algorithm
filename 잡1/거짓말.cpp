#include <bits/stdc++.h>
using namespace std;

#define MAX 51

// 구라친 파티 넘버
int board[MAX];
int notlied[MAX];
// 해당 파티에 참가한 사람 
vector <int> v[MAX];
// 사람이 참가한 파티 
vector <int> v2[MAX];

void erase1(int k) {
    for(int i : v[k]) {  
        notlied[i] = 1;
        for(int j : v2[i]){
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

    int n, m, knows;
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
            v[i].push_back(a);
            v2[a].push_back(i);
            if (notlied[a]) {
                flag = 1;
            }
        }
        if(!flag) {
            board[i] = 1;
            continue;
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
#include <bits/stdc++.h>
using namespace std;
#define MAX 15

int n, m;

int vis[MAX];
int flag1, flag2;
char board[MAX];
char arr[MAX];

int back(int k) {
    if(k == n) {
        if(!(flag1 >= 1 && flag2 >= 2)) return 0;
        for(int i = 0 ; i < n ; i++) cout << arr[i];
        cout << '\n';
        return 0;
    }
    for(int i = 0 ; i < m ; i++) {
        if(k != 0 && arr[k-1] > board[i]) continue;
        if (vis[i]) continue;
        vis[i] = 1;
        arr[k] = board[i];
        switch(arr[k]) {
            case 'a':
            case 'e':
            case 'i':
            case 'o':
            case 'u':
                flag1++;
                break;
            default:
                flag2++;
                break;
        }
        back(k + 1);
        switch(arr[k]) {
            case 'a':
            case 'e':
            case 'i':
            case 'o':
            case 'u':
                flag1--;
                break;
            default:
                flag2--;
                break;
        }
        vis[i] = 0;
    }
    arr[k] = 0;
    return 0;
}

int main (void) {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cin >> n >> m;
    for(int i = 0 ; i < m ; i++) cin >> board[i];
    sort(board, board + m);
    back(0);
    return 0;
}
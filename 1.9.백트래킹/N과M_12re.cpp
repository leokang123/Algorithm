#include <bits/stdc++.h>
using namespace std;

#define MAX 8
int n, m;
int vis[MAX];
int arr[MAX];
int board[MAX];
int back (int k) {
    if(k == m) {
        for(int i = 0 ; i < m ; i++) cout << arr[i] << ' ';
        cout << '\n';
        return 0;
    }
    for(int i = 0 ; i < n ; i++) {
        if(k!=0 && arr[k-1] > board[i]) continue;
        // 미리 설정한 arr[k]와 같은 board[i]값이 나오면 걸러준다 
        if(arr[k] == board[i]) continue;
        arr[k] = board[i];
        back(k + 1);
    }
    // 포문 벗어나면 초기화 해줘야함 
    arr[k] = 0;
    return 0;
}

int main(void) {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    cin >> n >> m;
    int k = 0;
    for(int i = 0 ; i < n ; i++){ 
        cin >> board[i];
    }
    sort(board,board+n);
    back(0);
    return 0;
}
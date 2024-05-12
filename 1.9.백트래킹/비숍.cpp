#include <bits/stdc++.h>
using namespace std;
#define MAX 10

int n, cnt1, cnt2, max1, max2;
int board[MAX][MAX];
int vis1[MAX * 2];
int vis2[MAX * 2];

int back1 (int k) {
    if (max1 < cnt1) max1 = cnt1;
    // 이게 최대값임 
    if (max1 == n - 1) return 0; 
    for (int i = k ; i < n * n ; i ++) {
        int crow = i / n;
        int ccol = i % n;
        if ((crow + ccol) % 2 != 0) continue;
        if (board[crow][ccol] != 1) continue;
        if (vis1[crow + ccol] || vis2[n - 1 + (ccol - crow)]) continue;
        vis1[crow + ccol] = 1;
        vis2[n - 1 + (ccol - crow)] = 1;
        cnt1++;
        back1(i + 1);
        cnt1--;
        vis1[crow + ccol] = 0;
        vis2[n - 1 + (ccol - crow)] = 0;
    }
    return 0;
}

int back2 (int k) {
    if (max2 < cnt2) max2 = cnt2;
    // 이게 최대값임 
    if (max2 == n - 1) return 0;
    for (int i = k ; i < n * n ; i++) {
        int crow = i / n;
        int ccol = i % n;
        if ((crow + ccol) % 2 != 1) continue;
        if (board[crow][ccol] != 1) continue;
        if (vis1[crow + ccol] || vis2[n - 1 + (ccol - crow)]) continue;
        vis1[crow + ccol] = 1; 
        vis2[n - 1 + (ccol - crow)] = 1;
        cnt2++;
        back2(i + 1);
        cnt2--;
        vis1[crow + ccol] = 0;
        vis2[n - 1 + (ccol - crow)] = 0;
    }
    return 0;
}

int main (void) {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    cin >> n;
    for (int i = 0 ; i < n ; i++) {
        for (int j = 0 ; j < n ; j++) cin >> board[i][j];
    }
    back1(0);
    back2(1);
    cout << max1 + max2 << '\n';
    return 0;
}
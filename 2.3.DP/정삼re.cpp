#include <bits/stdc++.h>
using namespace std;
#define MAX 501

int arr[MAX][MAX];

int main(void) {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n ; cin >> n;
    for(int i = 1 ; i <= n ; i++) {
        for(int j = 0 ; j < i ; j++) {
            cin >> arr[i][j];
        }
    }
    for(int i = n ; i > 1 ; i--) {
        for(int j = 0 ; j < i-1 ; j++) {
            arr[i-1][j] += max(arr[i][j], arr[i][j+1]);
        }
    }
    cout << arr[1][0] << '\n';
    return 0;
}
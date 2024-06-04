#include <bits/stdc++.h>
using namespace std;

int board[2];
int min1 = 1000000001 * 2;
int main (void) {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n; cin >> n;
    vector<int> arr(n);
    for(auto& i: arr) cin >> i;
    for(int i = 0 ; i < n ; i++) {
        int key = -1 * arr[i];
        int high = n;
        int low = -1;
        while (high > low + 1) {
            int mid = (high + low) / 2;
            if(arr[mid] >= key) high = mid;
            else low = mid;
        }
        cout << arr[low] << ' ' << arr[high] << '\n';
        for(int j = low; j <= high ; j++) {
            if(j < 0 || j >= n || i == j) continue;
            if (min1 > abs(arr[i] + arr[j])) {
                min1 = abs(arr[i] + arr[j]);
                board[0] = arr[i];
                board[1] = arr[j];
            }
        }
    }
    if(board[0] > board[1]) swap(board[0],board[1]);
    cout << board[0] << ' ' << board[1] << '\n';
}
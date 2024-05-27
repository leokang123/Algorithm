#include <bits/stdc++.h>
using namespace std;
int arr[1001];

int main (void) {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n; cin >> n;
    for(int i = 0 ; i < n ; i++) cin >> arr[i];
    sort(arr, arr + n);
    int sum = 0;
    int a = 0;
    for(int i = 0 ; i < n ; i++) {
        a += arr[i];
        sum += a;
    }
    cout << sum << '\n';

    return 0;
}
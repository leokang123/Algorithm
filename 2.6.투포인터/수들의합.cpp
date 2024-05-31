#include <bits/stdc++.h>
using namespace std;

int arr[10001];
int n, k;

void brute (void) {
    int cnt = 0;
    for (int i = 0 ; i < n ; i++) {
        int num = arr[i];
        int j = i + 1;
        while(num < k) num += arr[j++];
        if(num == k) cnt++;
    }
    cout << cnt << '\n';
}

int main (void) {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cin >> n >> k;
    for (int i = 0 ; i < n ; i++) cin >> arr[i];
    brute();
}
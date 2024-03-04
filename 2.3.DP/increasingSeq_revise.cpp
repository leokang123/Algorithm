#include <bits/stdc++.h>
using namespace std;

int memo[1001];
int arr[1001];
int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N; cin>> N;
    int max1 = 0;
    for(int i = 0 ; i < N; i++) cin >> arr[i];
    for(int i = 0 ; i < N ;i++) {
        memo[i] = arr[i];
        for(int j = 0 ; j < i ; j++) {
            if(arr[j] >= arr[i]) continue;
            memo[i] = max(memo[i], memo[j] + arr[i]);
        }
        max1 = max(memo[i],max1);
    }
    cout << max1 << '\n';
}
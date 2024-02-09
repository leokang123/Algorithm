#include <bits/stdc++.h> 
using namespace std;

int memo[1001];
int arr[1001];

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N; cin >> N;
    int max = 0;
    for(int i = 0 ; i < N ; i++) {
        cin >> arr[i];
        memo[i] = arr[i];
    }
    for(int i = 0 ; i < N ; i++) {
        for(int j = i + 1; j < N; j++) {
            if(arr[i] >= arr[j]) continue;
            if(memo[j] <= memo[i] + arr[j]) memo[j] = memo[i] + arr[j];
        }
        if(max < memo[i]) max = memo[i];
        // for(int i = 0 ; i < N; i++) cout << memo[i] <<' ' ;
        // cout << '\n';
    }
    cout << max << '\n';
}

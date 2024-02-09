#include <bits/stdc++.h>
using namespace std;

int memo[301][3];
int arr[301];

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N; cin >> N;
    for(int i = 1 ; i <= N ; i++) cin >> arr[i];
    memo[1][1] = arr[1];
    memo[1][2]  = 0;
    memo[2][1] = arr[2];
    memo[2][2] = arr[1] + arr[2];
    for(int i = 3 ; i <= N ; i++) {
        memo[i][1] = max(memo[i-2][2],memo[i-2][1]) + arr[i];
        memo[i][2] = memo[i-1][1] + arr[i];
    }
    cout << max(memo[N][1],memo[N][2]) << '\n';
}
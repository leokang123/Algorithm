#include <bits/stdc++.h>
using namespace std;



int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N; cin >> N;
    while(N--) {
        int memo[10001] = {0,};
        int arr[21] = {0,};
        int num; cin >> num;
        for(int i = 1; i <= num; i++) {
            cin >> arr[i];
        }
        int tot; cin >> tot;
        memo[0] = 1;
        for(int i = 1 ; i <= num; i++) {
            for(int j = 0 ; j + arr[i] <= tot ; j++) {
                memo[j + arr[i]] += memo[j];
            }
        }
        cout << memo[tot] << '\n';
    }
}

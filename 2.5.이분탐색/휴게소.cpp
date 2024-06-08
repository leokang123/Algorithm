#include <bits/stdc++.h>
using namespace std;

int arr[52];
int main (void) {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n, m, l; cin >> n >> m >> l;
    arr[n+1] = l;
    for(int i = 1 ; i <= n ; i++) cin >> arr[i];
    sort(arr+1, arr + n+1);    

    // 이미 설치되어있는 곳은 설치하면 안되니까 범위에서 1 을 뺴는게 중요하다 
    for(int i = 1; i <= n+1 ; i++) arr[i-1] = arr[i] - arr[i-1]-1;
    sort(arr, arr + n+1);
    int high = l;
    int low = 0;
    while (high > low + 1) {
        int cnt = 0;
        int mid = (high + low) / 2;
        for(int i = 0; i <= n ; i++) {
            cnt += arr[i] / mid;
        }
        cnt <= m ? high = mid : low = mid;
    }
    cout << high << '\n';
    return 0;
}
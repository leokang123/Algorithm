#include <bits/stdc++.h>
using namespace std;

int main (void) {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n, h; cin >> n >> h;
    vector<int> arr(h+1);
    for (int i = 0 ; i < n ; i++) {
        int a; cin >> a;
        if (i % 2 == 0) {
            arr[a]++;
        } else {
            arr[h]++;
            arr[h-a]--;
        }
    }
    int min1 = arr[h];
    int cnt = 1;
    for(int i = h; i > 1; i--) {
        arr[i-1] += arr[i];
        if (min1 > arr[i-1]) {
            cnt = 1;
            min1 = arr[i-1];
        } else if(min1 == arr[i-1]) cnt++;
    }
    cout << min1 << ' ' << cnt << '\n';
    return 0;
}
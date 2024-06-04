#include <bits/stdc++.h>
using namespace std;

int main (void) {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n; cin >> n;
    vector<int> cnt(1000002);
    vector<int> arr;
    int j = 0;
    for(int i = 0 ; i < n ; i++) {
        int a; cin >> a;
        if (i == 0 ) {
            arr.push_back(a);
            continue;
        }
        if (arr.back() >= a) {
            int idx = lower_bound(arr.begin(), arr.end(), a) - arr.begin();
            arr[idx] = a;
            continue;
        }
        arr.push_back(a);
    }
    cout << arr.size() << '\n';

    return 0;
}
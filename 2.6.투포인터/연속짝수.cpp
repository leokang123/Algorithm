#include <bits/stdc++.h>
using namespace std;

int main (void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k; cin >> n >> k;
    vector <int> arr(n);
    for(auto& i : arr) cin >> i;
    int j = 0;
    int max1 = 0;
    int num = 0;
    for (int i = 0 ; i < n ; i++) {
        while(j < n && k != -1) {
            if (arr[j] % 2 == 0) num++;
            else k--;
            j++;
        }
        max1 = max(max1, num); 
        if (arr[i] % 2 == 1) k++;
        else num--;
    }
    cout << max1 << '\n';
    return 0;
}
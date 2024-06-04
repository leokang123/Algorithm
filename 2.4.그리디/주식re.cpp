#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
// ll arr[1000001];

int main (void) {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n ; cin >> n;
    for(int i = 0 ; i < n ; i++) {
        int k ; cin >> k;
        vector<int> v;
        for(int j = 0 ; j < k ; j++) {
            int a ; cin >> a;
            v.push_back(a);
        }
        ll margin = 0;
        ll cost = 0;
        int max1 = 0;
        for(auto rit = v.rbegin() ; rit != v.rend(); rit++) {
            max1 = max(max1, *rit);
            if(*rit < max1) margin += max1 - *rit;
        }
        cout << margin << '\n';
    }
    // for(int i = 0 ; i < n ; i++) cout << arr[i] << '\n';
    return 0;
}
// 매번 max_element로 탐색하니까 시간초과 남 다른 방법필요 (반대로 탐색)

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll arr[1000001];

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
        ll b = *max_element(v.begin(), v.end());
        ll cnt = 0;
        ll margin = 0;
        ll cost = 0;
        for(auto it = v.begin() ; it != v.end(); it++) {
            if(*it == b) {
                margin += b * cnt - cost;
                cnt = 0;
                cost = 0;
                b = *max_element(it+1, v.end());
                continue;
            }
            cost += *it;
            cnt++;
        }
        arr[i] = margin;
        // cout << margin << '\n';
    }
    for(int i = 0 ; i < n ; i++) cout << arr[i] << '\n';
    return 0;
}
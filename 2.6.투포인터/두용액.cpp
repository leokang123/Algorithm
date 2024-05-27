//2473 백준
#include <bits/stdc++.h>
using namespace std;
#define MAX 100005

typedef long long ll;

ll check[MAX];
ll arr[3];
int main(void) {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int n; cin >> n;
    for(int i = 0 ; i < n ; i++) {
        cin >> check[i];
    }
    sort(check, check + n);
    ll min1 = (long long)2e15;
    int ed = n-1;
    for(int i = 0 ; i < n-1 ; i++) {
        while(i < ed) {
            ll ans = check[i] + check[ed];
            if(min1 > abs(ans)) {
                min1 = abs(ans);
                arr[0] = check[i];
                arr[1] = check[ed];
            }
            if(ans >= 0) ed--;
            else break;
        }
    }
    for(int i = 0 ; i < 2 ; i++) cout << arr[i] << ' ';
    cout << '\n';
    return 0;
}
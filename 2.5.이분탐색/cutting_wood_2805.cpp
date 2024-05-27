#include <bits/stdc++.h>
using namespace std;
#define MAX 1000001
int check[MAX];

int main (void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m; cin >> n >> m;
    int high = 0, low = 0, mid = 0;
    for(int i = 0 ; i < n ; i++) {
        cin >> check[i];
        high = max(high,check[i]);
    }
    high++;
    long long cnt = 0;
    int ans = 0;
    while(high > low +1) {
        cnt = 0;
        mid = (high + low) / 2;
        for(int i = 0 ; i < n ; i++) cnt += max(check[i]-mid, 0);
        if(cnt >= m) {
            low = mid;
        }else {
            high = mid;
        }
    }
    cout << low << '\n';

}
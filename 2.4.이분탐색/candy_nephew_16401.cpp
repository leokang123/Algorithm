#include <bits/stdc++.h>
using namespace std;
#define MAX 1000002
int n, m;
int check[MAX];

int main (void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m;
    int high = 0, low = 0, mid = 0 ;
    for(int i = 0 ; i < m ; i++) {
        cin >> check[i];
        high = max(high,check[i]);
    }
    high++;
    int cnt = 0;
    int ans = 0;
    while(high > low + 1) {
        cnt = 0;
        mid = (high + low) / 2;
        for(int i = 0 ; i < m ; i++) cnt += check[i] / mid;
        if(cnt >= n) {
            low = mid;
            ans = low;
        }else {
            high = mid;
        }
    }
    cout << ans << '\n';
    return 0;
}
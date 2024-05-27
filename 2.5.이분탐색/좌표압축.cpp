#include <bits/stdc++.h>
using namespace std;

int a[1000001];
int b[1000001];
int c[1000001];
int j;
int binSearch(int k ) {
    int high = j + 1;
    int low = -1;
    while(high > low + 1) {
        int mid = (high + low) / 2;
        if(b[mid] >= k) high = mid;
        else low = mid;
    }
    return high;
}
int main (void) {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int n ; cin >> n;
    for(int i = 0 ; i < n ; i++) {
        cin >> a[i];
        c[i] = a[i];
    }
    sort(a, a+n);
    for(int i = 1 ; i <= n ; i++){
        if(a[i] == a[i-1]) continue;
        b[j++] = a[i-1];
    }
    for(int i = 0 ; i < n ; i++) {
        cout << lower_bound(b,b+j,c[i]) - b << ' ';
    }
    cout << '\n';
}
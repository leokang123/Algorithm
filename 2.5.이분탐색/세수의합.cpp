#include <bits/stdc++.h>
using namespace std;
int a[1001];
long long b[1001 * 1001];
int n, s;
int binSearch(int k) {
    int high = s;
    int low = -1;
    while(high > low + 1) {
        int mid = (high + low) / 2;
        if(b[mid] == k) return 0;
        if(b[mid] > k) high = mid;
        else low = mid;
    }
    return 1;
}
int main(void) {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    cin >> n;
    int max1 = 0;
    for(int i = 0 ; i < n ; i++) {
        cin >> a[i];
    }
    sort(a, a+n);

    for(int i = 0 ; i < n ; i++) {
        for(int j = i ; j < n ; j++) {
            b[s++] = a[i] + a[j];
        }
    }
    sort(b, b + s);
    long long max2 = 0;
    // 끝에것이 어차피 되었다했을떄 최대라 한다면 굳이 최댓값을 구하지 않고 역순으로 구하면 바로 최댓값이 나온다 잘 활용하자 
    for(int i = n-1 ; i >= 0 ; i--) {
        for(int j = 0 ; j < i ; j++) {
            if(binSearch(a[i] - a[j])) continue;
            cout << a[i] << '\n';
            return 0;
        }
    }
}
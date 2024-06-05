#include <bits/stdc++.h>
using namespace std;
int n, m;

bool cal(int k, vector<int>& arr) {
    int cnt = 0;
    int min1 = 10000;
    int max1 = -1;
    for (auto i : arr) {
        if (min1 > i) min1 = i;
        if (max1 < i) max1 = i;
        if (max1 - min1 > k) {
            cnt++;
            min1 = i;
            max1 = i;
        }
    }
    return cnt < m;
}

int main (void) {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cin >> n >> m;
    vector<int> arr(n);
    for(auto&i : arr) cin >> i;
    int low = -1;
    int high = 10000;
    while (high > low + 1) {
        int mid = (high + low) / 2;
        // cnt = cal(mid,arr)
        // cnt가 m보다 같거나 클때 최대값인경우 cnt가 m과 같지 않을것이기때문에 low의 경우는 정답이 아니다
        // cnt가 m보다 작지만 low는 m과 같거나 큰경우가 우리가 원하는 경계값이다 
        cal(mid,arr) ? high = mid : low = mid;
    }
    cout << high << '\n';
    return 0;
}
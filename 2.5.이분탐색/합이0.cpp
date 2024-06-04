#include <bits/stdc++.h>
using namespace std;

int main (void) {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n ; cin >> n ;
    vector<int> v(n);
    for (auto& i : v) cin >> i;
    sort(v.begin(), v.end());
    long long cnt = 0;
    for (int i = 0 ; i < n ; i++) {
        for(int j = i+1; j < n ; j++) {
            int key = -1 *(v[i] + v[j]);
            // 이분 탐색 범위도 같이 줄여줘야 중복으로 탐색을 하지않는다 ...
            int idx1 = lower_bound(v.begin()+j+1,v.end(),key) - v.begin();
            int idx2 = upper_bound(v.begin()+j+1,v.end(),key) - v.begin();
            cnt += idx2 - idx1;
        }
    }
    cout << cnt << '\n';

}
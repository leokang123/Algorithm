// 메모리 초과.. 아마 두 수를 뺀 벡터가 크기를 넘어서는거 같다 
#include <bits/stdc++.h>
using namespace std;

int check[100001];
vector<int> v;

int binSearch(int k) {
    int high = v.size();
    int low = -1;
    while(high > low + 1) {
        int mid = (high + low) / 2;
        if(v[mid] >= k) high = mid;
        else low = mid;
    }
    return high;
}

int main (void) {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n, k;
    cin >> n >> k;
    for(int i = 0 ; i < n ; i++) cin >> check[i];
    sort(check, check + n);
    for(int i = n-1 ; i >= 0 ; i--) {
        for(int j = 0 ; j < i ; j++) {
            v.push_back(check[i] - check[j]);
        }   
    }
    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());
    int ans = binSearch(k);
    cout << v[ans] << '\n';
    
}
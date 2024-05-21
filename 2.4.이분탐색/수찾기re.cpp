// 메모리 초과.. 아마 두 수를 뺀 벡터가 크기를 넘어서는거 같다 
#include <bits/stdc++.h>
using namespace std;

int check[100001];
int n, k;
vector<int> v;

int binSearch(int k) {
    int high = n;
    int low = -1;
    while(high > low + 1) {
        int mid = (high + low) / 2;
        if(check[mid] >= k) high = mid;
        else low = mid;
    }
    return high;
}

int main (void) {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    cin >> n >> k;
    for(int i = 0 ; i < n ; i++) cin >> check[i];
    sort(check, check + n);
    int index = 0, min1 = (int)2e9;
    for(int i = 0 ; i < n ; i++) {
        index = binSearch(check[i] + k);
        if (index >= n) continue;
        min1 = min(min1, check[index] - check[i]);
    }
    
    cout << min1 << '\n';
    
}
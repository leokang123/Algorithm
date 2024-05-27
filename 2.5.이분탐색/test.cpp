#include <bits/stdc++.h>
using namespace std;

int main(void) {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    vector<int> v;
    int n ; cin >> n;
    while(n--) {
        int a ; cin >> a;
        v.push_back(a);
    }
    sort(v.begin(), v.end());
    for(int i : v) cout << i << ' ';
    cout << '\n';
    int high = v.size();
    int low = -1;
    // int low = 0;
    int num; cin >> num;
    while(high > low + 1) {
    // while(high > low) {
        int mid = (high + low) / 2;
        if(v[mid] == num) cout << "HERE: " << mid << '\n';
        if(v[mid] >= num) high = mid;
        else low = mid;
        // else low = mid + 1;
    }
    cout << low << ' ' << high;
}
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(void) {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int candy, num; cin >> candy >> num;
    ll sum = 0;
    vector<ll> arr(num);
    for (auto&i : arr) {
        cin >> i;
        sum += i;
    }
    sort(arr.begin(), arr.end());
    ll useSum = 0;
    ll low = 0;
    ll high = (int)(2e9) + 1;
    ll left = sum - candy;
    while(high > low + 1) {
        sum = 0 ;
        ll mid = (high + low) / 2;
        for(auto i : arr) {
            sum += max(i - mid, (ll)0);
        }
        if (sum <= candy) {
            high = mid;
            useSum = sum;
        } else low = mid;
    }
    candy = candy- useSum;
    sum = 0;
    for (int i = num-1 ; i >= 0 ; i--) {
        if (arr[i] > high) arr[i] = high;
        if (candy-- > 0) arr[i] -= 1;
        sum += arr[i] * arr[i];
    }
    cout << sum << '\n';
    return 0;
}
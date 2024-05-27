//2473 백준
#include <bits/stdc++.h>
using namespace std;
#define MAX 100005

typedef long long ll;

ll check[MAX];
ll arr[3];
int main(void) {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int n; cin >> n;
    for(int i = 0 ; i < n ; i++) {
        cin >> check[i];
    }
    sort(check, check + n);
    ll min1 = (long long)2e15;
    for(int i = 0 ; i < n ; i++) {
        int high = n;
        int low = -1;
        while(high > low + 1) {
            int mid = (high + low) / 2;
            if(i == mid)break;
            if(min1 > abs(check[mid] + check[i])) {
                min1 = abs(check[mid] + check[i]);
                arr[0] = check[i];
                arr[1] = check[mid];
            }
            if(check[mid] + check[i] >= 0){
                high = mid;
            }
            else {
                low = mid;
            }
        }

    }
    sort(arr,arr+2);
    for(int i = 0 ; i < 2 ; i++) cout << arr[i] << ' ';
    cout << '\n';
    return 0;
}
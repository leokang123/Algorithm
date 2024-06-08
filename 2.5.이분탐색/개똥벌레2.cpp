#include <bits/stdc++.h>
using namespace std;

int up[500010];
int down[500010];
int arr2[500010];
int main (void) {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n, h; cin >> n >> h;
    for (int i = 0 ; i < n ; i++){
        int a; cin >> a;
        if (i % 2 == 0) down[a]++;
        else up[a]++;
    }

    for(int i = h ; i>= 1 ; i--) {
        up[i] += up[i+1];
        down[i] += down[i+1];
    }
    int min1 = down[1];
    int cnt = 0;
    for(int i = 1; i <= h; i++) {
        arr2[i-1] = down[i]+ up[h-i+1];
        if(min1 > arr2[i-1]) {
            min1 = arr2[i-1];
            cnt = 1;
        }
        else if(min1 == arr2[i-1]) cnt++;
    }
    cout << min1 << ' ' <<  cnt << '\n';
    return 0;
}
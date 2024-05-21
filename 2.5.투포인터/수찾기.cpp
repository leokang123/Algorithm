#include <bits/stdc++.h>
using namespace std;

int check[100001];
// int main(void) {
//     cin.tie(nullptr);
//     ios::sync_with_stdio(false);

//     int n, k ; cin >> n >> k;
//     for(int i = 0 ; i < n ; i++) cin >> check[i];
//     sort(check, check+n);
//     int min1 = (int)2e9;
//     for(int i = n-1 ; i >= 0 ; i--) {
//         for(int j = 0 ; j < i; j++) {
//             if(check[i] - check[j] < k) continue;
//             min1 = min(min1, check[i] - check[j]);
//         }
//     }
//     cout << min1 << '\n';
// }

/* 위 코드를 투포인터를 통해 O(N) 복잡도로 바꿀거임 */

int main(void) {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n, k ; cin >> n >> k;
    for(int i = 0 ; i < n ; i++) cin >> check[i];
    sort(check, check+n);
    int min1 = (int)2e9;
    int ed = 0;
    for(int st = 0 ; st < n ; st++) {
        while(ed < n && check[ed] - check[st] < k) ed++;
        if(ed == n) break;
        min1 = min(min1, check[ed] - check[st]);
    }
    cout << min1 << '\n';
}
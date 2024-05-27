#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int check[10001];

int main(void) {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n, k; cin >> n >> k;
    for(int i = 0 ; i < n ; i++) cin >> check[i];
    sort(check, check + n);
    // 여기서 check이 int 형이라 임시 변수에 담겨져서 1로 더할때 오버플로우가 발생해서 에러가 났다 
    // 따라서 명시적 형변환을 통해 오버플로우를 방지하거나 첨부터 check배열을 long long으로 선언해야한다 
    // 아니면 이분 탐색 범위를 좁혀서 하거나 (취향차이)
    ll high = (long long)check[n-1] + 1;
    ll low = 0;
    int cnt = 0, ans = 0;
    while(high > low + 1) {
        cnt = 0;
        int mid = (high + low) / 2;
        for(int i = 0 ; i < n ; i++) cnt += check[i] / mid;
        if(cnt >= k) {
            low = mid;
            ans = low;
        }
        else high = mid;
    }
    cout << ans << '\n';
}
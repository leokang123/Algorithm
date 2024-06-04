#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main (void) {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    ll n;
    int k; cin >> n >> k;
    ll high = n * n  + 1;
    ll low = 0;
    while(high > low + 1) {
        ll cnt = 0;
        ll mid = (high + low) / 2;
        for(ll i = 1 ;i <= n ; i++) cnt += min(mid/i, (ll)n);
        cnt >= k ? high = mid : low = mid;
    }
    cout << high << '\n';
    return 0;
}
/*
    이 문제에서 대체 왜 최적의 답이 나올까 고민했다 예를 들어 3 입력과 5번째 인덱스를 구하라고 하면 
    위방식대로 하면 1 2 2 3 3 4 6 6 9 이런 순서대로 배열이 짜여질거고 5번째니까 3이 답일텐데 
    따로 배열을 쓰는것도 아니고 그냥 숫자 두개의 mid값을 갱신하는 형태로 이분탐색을 진행하는데 3이 어떻게 배열에 있을줄 알고 
    답을 3으로 내는지 고민을 많이 했다 
    고민한 결과 이분탐색은 "low 와 high가 명확한 경계"를 가지는 탐색이다
    값이 low와 high를 기점으로 변하고 그 사이에 간격이 1인 부분을 찾는 탐색이라 볼 수 있다 
    따라서 위 예시에서 3 7 과 같은 입력을 했을떄 5와 같은 정답이 안생기는 이유는 4와 5 사이에는 아무런 경계가 없기 때문이다 
    4도 위 코드에 따르면 cnt 가 3 + 2 + 1(6) 이 나오고 5도 3 + 2 + 1 아 나오기 때문에 경계가 아니다 
    하지만 6의 경우 cnt가 3 + 3 + 2(8) 이므로 5와 6사이에 확실한 경계가 생긴다 
    따라서 low = 5, high = 6으로 탐색을 마치고 3 7 에 답을 6으로 내게 된다 
    결론적으로 경계가 되는 값의 high 값은 해당 배열에 존재할수 밖에 없다 (경계가 생겨야하고, 규칙을 이미 행를 기준으로 cnt를 더해주는 식으로 짜줬기 때문에)
*/
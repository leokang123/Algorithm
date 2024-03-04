// red : 0, green : 1, blue : 2
#include <bits/stdc++.h> 
using namespace std;

int memo[1001][3];
int cost[1001][3];

int main (void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; cin >> n;
    for(int i = 0 ; i < n; i++) {
        for(int j = 0 ; j < 3; j++) cin >> cost[i][j];
    }
    memo[0][0] = cost[0][0];
    memo[0][1] = cost[0][1];
    memo[0][2] = cost[0][2];
    for (int i = 1 ; i < n ; i++) {
        memo[i][0] = min(memo[i-1][1],memo[i-1][2]) + cost[i][0];
        memo[i][1] = min(memo[i-1][0],memo[i-1][2]) + cost[i][1];
        memo[i][2] = min(memo[i-1][1],memo[i-1][0]) + cost[i][2];
    }
    cout << min({memo[n-1][0],memo[n-1][1],memo[n-1][2]}) << '\n';
    // min 함수안에 {} 를 통해 배열로 인자를 보낼수도 있따 
    return 0;

}

// 비교적 간단한 문제임에도 좀 헤맨게 아직 DP 를 잘 모르는거 같다 가장 중요한 테이블 정하는 부분에서
// 답에대한 고민만 깊게 하다보니 먼가 잘 안잡힌다 그냥 DP는 적절한 테이블을 잘 정의 하고 동작하게 만들면 답은 알아서 나오는 느낌? 그런 느낌을 받는다 
// 처음에는 이 세개를 비교해서 머.. 가장 작은걸 뽑고 이것저것 막 고민했는데
// 실상은 이 값이 빨강(혹은 다른색) 임을 가정하고 그 전상황에대한 최솟값을 각각 구하는느낌? 
// 초기값을 잘 설정했다면 차곡차곡 잘 값이 쌓였을 것이기때문에 전집의 색중 가장 작은것과 더해주기만하면 끝이다 
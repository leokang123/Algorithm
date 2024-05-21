//2473 백준
#include <bits/stdc++.h>
using namespace std;
#define MAX 5005

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
    // for(int i = 0 ; i < n ; i++) cout << check[i] << ' ' ;
    cout << '\n';
    ll min1 = (long long)2e15;
    for(int i = 0 ; i < n-2 ; i++) {
        int st1 = i+1,  st2 = n-1;
        while(st1 < st2) {
            ll ans = check[i] + check[st1] + check[st2];
            if(min1 > abs(ans)) {
                min1 = abs(ans);
                arr[0] = check[i];
                arr[1] = check[st1];
                arr[2] = check[st2];
            }

            /**정렬되어있기 때문에 가능한 방식 
             * 이렇게도 순회할수 있다는것을 기억해두자 
             * 0과 가까운 값을 찾아나가는 과정인데 그럼 이중간에 몇개 빼먹는거 아니냐 할수 있는데  
             * 정렬되어있기 때문에 빼먹은 경우는 애초에 올바르지 않은 상황이다 그냥 
             * ans >= 0 조건은 0을 기준으로 범위를 좁혀가는 과정이다 
             * 좁혀가는 과정에 모든 경우는 기록하면서 진행된다 */ 
            if(ans >= 0) st2--;
            else st1++;
        }
    }
    for(int i = 0 ; i < 3 ; i++) cout << arr[i] << ' ';
    cout << '\n';
    return 0;
}
#include <bits/stdc++.h>
using namespace std;

int arr[301];

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; cin >> n;
    int tot = 0;
    for (int i = 1 ; i <= n; i++) {
        cin >> arr[i];
        tot += arr[i];
    }
    if(n <= 2) {
        cout << tot <<'\n';
        return 0;
    }
    // 각각 i번쨰 계단을 밟지 않았을때 얻을수 있는 밟지않은 계단점수의 최솟값(반대로 얘기해서 최댓값을 가지는 계단을 밟는경우임) 
    arr[1] = arr[1]; // 1번 계단 안 밟았을때 
    arr[2] = arr[2]; // 2번 계단을 밟지 않았을떄 (1번 계단을 밟아야 최대가됌) 
    arr[3] = arr[3]; // 3번 계단을 밟지 않았을떄 (1,2번계단을 밟아야 최대가 됌) 
    arr[4] = arr[4] + min(arr[1],arr[2]);   // 4번 계단을 밟지 않았을때 (3번은 무조건 밟아야 됌)
    for(int i = 5 ; i <= n ; i++) {
        arr[i] = arr[i] + min(arr[i-2],arr[i-3]);
    }
    cout << tot - min(arr[n-1],arr[n-2]) << '\n';
    return 0;
}
#include <bits/stdc++.h>
using namespace std;
#define MAX 20
int count1;
int arr[MAX];
int isused[MAX];
int partial;
int sum;
int N,S;
void func1(int n){
    if(n == N) return;
    for(int i = n;i < N;i++){
        if(!isused[i]){
            isused[i] = 1;
            sum += arr[i];
            if(sum == S) count1++;
            // cout << "N: "<<n<<' '<<"arr: "<<arr[i]<<" sum: "<<sum<<'\n';
            // 예시입력 -7 -3 -2 5 8 에서 그냥 하면 6개 나옴
            // 답이 -3,-2,5 이라 가짓수가 6가지라서 6개 나옴 
            func1(i+1); // 순서대로 만 찾게 해서 막음
            isused[i] = 0;
            sum -= arr[i];
        }
    }
}

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N>> S;
    for(int i = 0; i < N; i++) cin >> arr[i];
    func1(0);
    cout << count1<<'\n';
}
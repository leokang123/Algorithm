#include <bits/stdc++.h>
using namespace std;
#define MAX 9
bool isused[MAX];
int arr[MAX];
int N,M;
void func1(int k){
    if(k==M){ // 마지막 leaf노드 일때 지금까지의 경로를 출력해라 라는 뜻이랑 같음 
        for(int i = 0;i < M;i++){
            cout << arr[i]<<' ';
        }
        cout << '\n';
        return;
    }
    for(int i = 1;i <=N;i++){
        if(!isused[i]){
            arr[k] = i;
            isused[i] = 1;
            // i를 사용했으니 이제 사용하지마라는 뜻 
            func1(k+1);
            isused[i] = 0;
        }
    }
}

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N >> M;
    func1(0);
    return 0;
}
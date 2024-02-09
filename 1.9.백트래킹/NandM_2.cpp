#include <bits/stdc++.h>
using namespace std;
#define MAX 25
int arr[MAX];
bool isused[MAX];
int N,M;

void func1(int k){
    if(k == M){
        for(int i = 0; i < M ; i++){
            cout << arr[i] <<' ';
        }
        cout <<'\n';
        return;
    }
    for(int i = 1; i <= N ; i++){
        if(!isused[i]){
            arr[k] = i;
            // 백트래킹에 조건식 하나만 추가되는식으로 노드들에 차등을 준다 
            if(k != 0 && arr[k-1] > arr[k]) continue; 
            isused[i] = 1;
            func1(k+1);
            isused[i] = 0;
        }
    }
}

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N >> M ;
    func1(0);
}
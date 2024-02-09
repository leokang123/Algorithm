#include <bits/stdc++.h>
using namespace std;
#define MAX 9

int ischeck[MAX];
int arr1[MAX];
int arr2[MAX];
int N,M;

// k 는 자릿수임 
void func(int k) {
    if( k == M ){
        for ( int i = 0 ; i < M ; i++ ){
            cout << arr2[i] <<' ';
        }
        cout << '\n';
        return;
    }
    for ( int i = 0 ; i < N ; i++ ){
        // k 자릿수에 이미 들어갔던 수와 입력한 수 배열에 같은 수가 있을시 무시, 이전 자릿수의 수보다 현재 자릿수에 들어가는 수가 작을시 무시 
        if ( arr2[k] == arr1[i] || (k != 0 && arr2[k-1] > arr1[i]) ) continue;
        arr2[k] = arr1[i];
        ischeck[i] = 1;
        func(k + 1);
        ischeck[i] = 0;
    }
    arr2[k] = 0;
}

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N >> M ;
    for ( int i = 0 ; i < N ; i++ ) {
      cin >> arr1[i];
    }
    sort(arr1, arr1 + N);
    func(0);
    return 0;
}
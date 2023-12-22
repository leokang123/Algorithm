#include <bits/stdc++.h>
using namespace std;
#define MAX 9

int arr1[MAX];
int arr2[MAX];
int N,M;

void func(int k) {
    if( k == M ){
        for ( int i = 0 ; i < M ; i++ ){
            cout << arr2[i] <<' ';
        }
        cout << '\n';
        return;
    }
    for ( int i = 0 ; i < N ; i++ ){
            arr2[k] = arr1[i];
            func(k + 1);
    }
}

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N >> M ;
    for( int i = 0 ; i < N ; i++ ) cin >> arr1[i];
    sort(arr1, arr1 + N);
    func(0);
    return 0;
}
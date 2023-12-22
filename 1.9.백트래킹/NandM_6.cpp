#include <bits/stdc++.h>
using namespace std;
#define MAX 9

int arr1[MAX];
int arr2[MAX];
int ischeck[MAX];
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
        // if(!ischeck[i]){
            arr2[k] = arr1[i];
            if( k != 0 && arr2[k] < arr2[k-1] ) continue;
            // ischeck[i]  = 1;
            func(k + 1);
        //     ischeck[i]  = 0;
        // }
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
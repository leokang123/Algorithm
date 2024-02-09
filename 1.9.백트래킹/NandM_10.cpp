#include <bits/stdc++.h>
using namespace std;
#define MAX 9

int ischeck[MAX];
int arr1[MAX];
int arr2[MAX];
int arr3[10000];
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
        if(!ischeck[i]) {
        if ( arr2[k] == arr1[i] || (k != 0 && arr2[k-1] > arr1[i]) ) continue;
          arr2[k] = arr1[i];
          ischeck[i] = 1;
          func(k + 1);
          ischeck[i] = 0;
        }
    }
    arr2[k] = 0;
}

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N >> M ;
    for ( int i = 0 ; i < N ; i++ ) {
      cin >> arr1[i];
      arr3[arr1[i]] += 1;
    }
    sort(arr1, arr1 + N);
    func(0);
    return 0;
}
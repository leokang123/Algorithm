#include <bits/stdc++.h>
using namespace std;

#define MAX 9
int N, M;
int arr[MAX];
// int ischeck[MAX];
void func(int num){
    if ( M == num ){
        for ( int i = 0 ; i < M ; i++ ){
            cout << arr[i]<<' ';
        }
        cout << '\n';
        return;
    }
    for ( int i = 1; i <= N ; i++ ){
        if ( num == 0 || arr[num-1] <= i ){
            arr[num] = i;
            func(num+1);
        }
    }
}

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N >> M;
    func(0);
    return 0;
}
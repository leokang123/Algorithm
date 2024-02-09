#include <bits/stdc++.h>
using namespace std;

#define MAX 15 
int arr1[MAX];
int arr2[MAX];
int ischeck[MAX];
int N;
void func(int k) {
    if (k == 6) {
        for(int i = 0 ; i < 6 ; i++) cout << arr2[i]<<' ';
        cout << '\n';
        return;
    }
    for (int i = 0 ; i < N ; i++) {
        if (!ischeck[i]) {
            if (k != 0 && arr2[k-1] > arr1[i]) continue;
            ischeck[i] = 1;
            arr2[k] = arr1[i];
            func(k + 1);
            ischeck[i] =  0;
        }
    }
    arr2[k]  = 0;
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    while(cin >> N && N != 0){
        for (int i = 0 ; i < N ; i++) cin >> arr1[i];
        func(0);
        cout << '\n';
    }
    return 0 ;
}
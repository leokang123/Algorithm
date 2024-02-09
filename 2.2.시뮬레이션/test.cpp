#include <bits/stdc++.h>
using namespace std;
int arr[5];
int check[5];

void backTrack(int n ){
    if(n == 5){
        for(int i : arr) cout << i << ' ';
        cout << '\n';
        return ;
    }
    for(int i = 0 ; i < 5 ; i++) {
        if(!check[i]){
            check[i] = 1;
            arr[n] = i;
            backTrack(n + 1);
            check[i] = 0;
        }
    }
}

int main(void ) {
    backTrack(0);
}
#include <bits/stdc++.h>
using namespace std;

int memo[125251];
int arr[125251];
int main (void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N ; cin >> N;
    int a = 1;
    for(int i = 1; i <= N; i++) {
        for(int j = 0 ; j < i ; j++) {
            cin >> arr[a];
            if(i == N){
                memo[a] = arr[a];
            }
            a++;
        }
    }
    // 0: 왼쪽에서 더해진거, 1: 오른쪽에서 더해진거 
    int lev = N;
    int rep = 0; 
    int num = a - 1;
    for(int i = num ; i >= 2; i--) {
        if(rep == lev){ 
            lev--;
            rep = 0;
        }
        memo[i-lev] = arr[i-lev] + max(memo[i], memo[i-1]);
        rep++;
    }
    cout << memo[1] << '\n';
}
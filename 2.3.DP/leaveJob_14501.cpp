#include <bits/stdc++.h> 
using namespace std;

int arr[15][2];
int memo[15];

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N ; cin >> N ;
    for(int i = 0 ; i < N ; i++) {
        cin >> arr[i][0] >> arr[i][1];
        memo[i] =  arr[i][1];
    }
    int max = 0;
    for(int i = 0 ; i < N ; i++) {
        int skip = arr[i][0];
        int pay = arr[i][1];
        for(int j = i + skip; j < N ; j++) {
            if(memo[j] < memo[i] + arr[j][1]) memo[j] = memo[i] + arr[j][1];
        }
        if(i + skip <=  N && max < memo[i]) max = memo[i];
       
    }
    cout << max << '\n';
}
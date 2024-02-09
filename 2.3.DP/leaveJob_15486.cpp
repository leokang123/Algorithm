#include <bits/stdc++.h> 
using namespace std;
#define MAX 1500001

int arr[MAX][2];
int memo[MAX];
int N ;
void showM(){
    for(int i = 0 ; i < N+1 ; i++) {
        cout << memo[i] << ' ';
    }
    cout << '\n';
} 

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N ;
    for(int i = 0 ; i < N ; i++) {
        cin >> arr[i][0] >> arr[i][1];
        // memo[i] =  arr[i][1];
    }

    int max1 = 0 ;
    for (int i = 0 ; i < N+1 ; i++) {
        memo[i] = max(max1,memo[i]);
        if(i + arr[i][0] <= N) memo[i + arr[i][0]] = max(memo[i] + arr[i][1], memo[i + arr[i][0]]);
        max1 = max(memo[i], max1);
        cout << memo[N] << '\n';
        showM();
    }
    cout << max1 << '\n';
}


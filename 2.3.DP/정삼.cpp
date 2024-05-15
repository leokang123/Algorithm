#include <bits/stdc++.h>
using namespace std;
#define MAX 501

int arr[MAX][MAX]; 
int main(void) {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int cnt = 0;
    int max1 = 0;
    int n ; cin >> n;
    for(int i = 1; i <= n ; i++){
        for(int j = 0 ; j < i ; j++) {
            cin >> arr[i][j];
        }
    }

    for(int i = 2; i <= n ; i++) {
        int arr2[MAX] = {0,};
        for(int j = 0 ; j < i-1 ; j++) {
            arr2[j] = max(arr2[j], arr[i][j] + arr[i-1][j]);
            arr2[j+1] = max(arr2[j+1], arr[i][j+1] + arr[i-1][j]);
        }
        for(int j = 0 ; j < i ; j++) arr[i][j] = arr2[j];
    }
    for(int i = 0 ; i < n ; i++)  max1 = max(max1,arr[n][i]);
    cout << max1 << '\n';
}
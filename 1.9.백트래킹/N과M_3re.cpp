#include <bits/stdc++.h>
using namespace std;
#define MAX 7

int n,m;
int arr[MAX];

int back(int k) {
    if(k == m) {
        for(int i = 0 ; i < m ; i++) cout << arr[i] << ' ';
        cout << '\n';
        return 0;
    }
    for(int i = 0 ; i < n ; i++) {
        arr[k] = i + 1;
        back(k+1);
    }
    return 0;
}

int main (void) {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cin >> n >> m;
    back(0);
    return 0;
}
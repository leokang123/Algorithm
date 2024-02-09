#include <bits/stdc++.h>
using namespace std;
#define MAX 2000002
#define PIV 1000001
int arr[MAX];

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N ; cin >> N;
    for (int i = 0 ; i < N ; i++) {
        int a ; cin >> a;
        arr[PIV + a] = 1;
    }
    for(int i = MAX - 1 ; i >= 0;i--){
        if(!arr[i]) continue;
        cout << i - PIV <<'\n';
    }
    return 0;
}
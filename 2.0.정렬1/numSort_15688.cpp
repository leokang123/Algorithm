#include <bits/stdc++.h>
using namespace std;
#define MAX 2000002
#define PIV 1000001
int arr[MAX];

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    vector<int> v;
    int N ; cin >> N;
    for (int i = 0 ; i < N ; i++) {
        int a ; cin >> a;
        arr[PIV + a]++;
    }
    for(int i = 0 ; i < MAX ;i++){
        if(!arr[i]) continue;
        for(int j = 0 ; j < arr[i] ; j++) cout << i - PIV <<'\n';
    }
    return 0;
}
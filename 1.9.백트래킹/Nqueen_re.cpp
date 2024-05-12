#include <bits/stdc++.h>
using namespace std;

#define MAX 15
int N;
int cnt;
int vis1[MAX]; 
int vis2[MAX * 2];  
int vis3[MAX * 2];  
                

int back(int n) {
    if(n == 0) {
        cnt++;
        return 0;
    }
    for (int i = 0 ; i < N ; i ++) {
        if(vis1[i] || vis2[n-1 + i] || vis3[N-1 - ((n-1) - i)]) continue;
        vis1[i] = 1;
        vis2[n-1 +i] = 1;
        vis3[N - 1 - ((n-1) - i)] = 1;
        back(n-1);
        vis1[i] = 0;
        vis2[n-1 +i] = 0;
        vis3[N - 1- ((n-1) - i)] = 0;
    }
    return 0;
}

int main(void) {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cin >> N;
    back(N);
    cout << cnt << '\n';
}
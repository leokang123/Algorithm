#include <bits/stdc++.h>
using namespace std;

#define MAX 8
int n, m;
int vis[MAX];
int arr[MAX];
int back (int k) {
    if(k == 0) {
        for(int i = 0 ; i < m ; i++) printf("%d ",arr[i]);
        printf("\n");
        return 0;
    }
    for(int i = 0 ; i < n ; i++) {
        if(vis[i]) continue;
        arr[m-k] = i + 1;
        vis[i] = 1;
        back(k-1);
        vis[i] = 0;
    }
    return 0;
}

int main(void) {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cin >> n >> m;
    back(m);
    
    return 0;
}
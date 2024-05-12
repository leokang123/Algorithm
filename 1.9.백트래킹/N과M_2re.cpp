#include <bits/stdc++.h>    
using namespace std;

#define MAX 8

int n, m;

int vis[MAX];
int arr[MAX];

int back(int k, int num) {
    if (num == m) {
        for(int i = 0 ; i < m ; i++) printf("%d ", arr[i]);
        printf("\n");
        return 0;
    }
    for (int i = k ; i < n ; i++) {
        if(vis[i]) continue;
        vis[i] = 1;
        arr[num] = i + 1;
        back(i, num + 1);
        vis[i] = 0;
    }
    return 0;
}

int main (void) {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cin >> n >> m ;
    back(0,0);
    return 0;

}
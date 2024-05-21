#include <bits/stdc++.h>
using namespace std;
#define MAX 101

int check[100002];
int pro1[MAX][2];

int main (void) {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n,w; cin >> n >> w;
    for(int i = 0 ; i < n ; i++) {
        cin >> pro1[i][0] >> pro1[i][1];
        
    }
    for(int i = 1 ; i <= n ; i++) {
        // 아마 이렇게 거꾸로 하는 이유는 순서대로하면 j 가 w처럼 클때 이미 더한값에 또 더할수 있기 때문이다 
        for(int j = w ; j >= pro1[i-1][0] ; j--){
            check[j] = max(pro1[i-1][1] + check[j-pro1[i-1][0]], check[j]);
        }
    }
    cout << check[w] << '\n';
}
#include <bits/stdc++.h>
using namespace std;

#define MAX 100001

int check[MAX][MAX];
int n, weight, max1;
int vis[MAX];

void printCheck() {
    for(int i = 0 ; i <=n ; i++) {
        for(int j = 0 ; j <= weight ; j++ ){
            cout << check[i][j] << ' ';
        }
        cout << '\n';
    }
}
int main (void) {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    pair<int, int> v[MAX];
    cin >> n >> weight;
    for (int i = 1 ; i <= n ; i++) {
        int a, b; cin >> a >> b;
        v[i] = {a,b};
    }
    int min1 ;
    for (int i = 1 ; i <= n ; i ++) {
        for(int j = 0 ; j <= weight ; j++) {
            if (v[i].first > j) check[i][j] = check[i-1][j];
            else {
                check[i][j] = max(check[i][v[i].first], check[i-1][j-v[i-1].first] + v[i].second);
            }
            max1 = max(max1, check[i][j]);
            printCheck();
            cout << "i: " << i << ' '<< "j: " << j << '\n';
        }
    }
    cout << max1 << '\n';

}
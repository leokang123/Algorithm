#include <bits/stdc++.h>
using namespace std;
#define MAX 41
pair<int, int> check[MAX];

pair<int, int> fivo(int k) {
    if(check[k].first != -1) return check[k];
    pair<int, int> cur1 = fivo(k-1), cur2 = fivo(k-2);
    check[k].first = cur1.first + cur2.first;
    check[k].second = cur1.second + cur2.second;
    return check[k];
}

int main(void) {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    fill(check, check + MAX, make_pair(-1,-1));
    int m; cin >> m;
    while(m--){
        int n ; cin >> n;
        check[0] = {1,0};
        check[1] = {0,1};
        pair<int,int> result = fivo(n);
        cout << result.first << ' ' << result.second << '\n';
    }
    return 0;
}
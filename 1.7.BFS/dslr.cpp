#include <bits/stdc++.h>
using namespace std;

int d(int k) {
    return (k * 2) % 10000;
}

int s(int k) {
    return (k - 1 + 10000) % 10000;
}

int l(int k) {
    return (k * 10) % 10000 + k / 1000;
}

int r(int k) {
    return k / 10  + (k % 10) * 1000;
}
int (*func[4])(int) = {d,s,l,r};
string sarr[4] = {"D", "S", "L", "R"};
int vis[10001];
int main(void) {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int n ; cin >> n;
    while(n--) {
        fill(vis, vis+10001, 0);
        int k1, k2; cin >> k1 >> k2;
        queue<pair<int, string>> q;
        q.push({k1,""});
        while(!q.empty()) {
            int fin = 0;
            auto [cs,ctr] = q.front(); q.pop();
            for(int i = 0 ; i < 4 ; i++) {
                int nx = func[i](cs);
                string str = ctr + sarr[i];
                if (nx < 0 || nx >= 10000) continue;
                if(vis[nx]) continue;
                if (nx == k2) {
                    cout << str << '\n';
                    fin = 1;
                    break;
                }
                vis[nx] = 1;
                q.push({nx,str});
            }
            if (fin) break;
        }
    }
    return 0;
}
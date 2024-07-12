#include <bits/stdc++.h>
using namespace std;

int main (void) {
  cin.tie(nullptr)->sync_with_stdio(false);
  set<int> s[2]; // 0, 1 
  unordered_map<int,int> m;
  int cur = 1;
  int n, q; cin >> n >> q;
  for (int i = 1 ; i <= n ; i++) {
    int a; cin >> a;
    m[i] = a;
    s[a].insert(i);
  }
  for (int i = 0 ; i < q ; i++) {
    int query; cin >> query;

    if (query == 1) {
      int tog; cin >> tog;
      s[m[tog]].erase(s[m[tog]].find(tog));
      m[tog] = !m[tog];
      s[m[tog]].insert(tog);
    } else if(query == 2) {
      int mv; cin >> mv;
      int prev = cur;
      cur = (cur-1 + mv) % n + 1;
      // cout << prev << "->" << cur << '\n';
    } else {
      if (s[1].empty()) {
        cout << -1 << '\n';
        continue;
      }
      auto it = s[1].lower_bound(cur);
      if (it == s[1].end()) {
        cout << *s[1].begin() + n - cur << '\n';
      }
      else cout << *it - cur << '\n';
    }
  }

  return 0;
}
#include <bits/stdc++.h>
using namespace std;

int main (void) {
  cin.tie(nullptr)->sync_with_stdio(false);
  set<int> s; // 0, 1 
  int cur = 1;
  int n, q; cin >> n >> q;
  for (int i = 1 ; i <= n ; i++) {
    int a; cin >> a;
    if (a == 1) s.insert(i);
  }
  for (int i = 0 ; i < q ; i++) {
    int query; cin >> query;

    if (query == 1) {
      int tog; cin >> tog;
      // if (s.count(tog)) s.erase(s.find(tog)); 이코드는 뭔가 count도 연산 find도 똑같은 연산을 하는 느낌? 
      auto it = s.find(tog);
      if (it == s.end()) s.insert(tog);
      else s.erase(it);
    } else if(query == 2) {
      int mv; cin >> mv;
      int prev = cur;
      cur = (cur-1 + mv) % n + 1;
      // cout << prev << "->" << cur << '\n';
    } else {
      if (s.empty()) {
        cout << -1 << '\n';
        continue;
      }
      auto it = s.lower_bound(cur);
      if (it == s.end()) {
        cout << *s.begin() + n - cur << '\n';
      }
      else cout << *it - cur << '\n';
    }
  }

  return 0;
}
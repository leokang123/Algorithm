#include <bits/stdc++.h>
using namespace std;

unordered_map<string, int> mp;

int main (void) {
  cin.tie(nullptr)->sync_with_stdio(false);

  int n; cin >> n;
  while (n--) {
    int m; cin >> m;
    for (int i = 0 ; i < m ; i++) {
      string a, b; cin >> a >> b;
      if (mp.find(b) != mp.end()) mp[b] += 1;
      else mp[b] = 1;
    }
    int res = 1;
    for (auto [k, v] : mp) {
      res *= (v+1);
    }
    cout << res - 1 << '\n';
    mp.clear();
  }
  return 0;
}
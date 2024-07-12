#include <bits/stdc++.h>
using namespace std;


int main (void) {
  cin.tie(nullptr)->sync_with_stdio(false);
  int n; cin >> n;
  set<pair<int,int>> m;
  unordered_map<int,int> um;
  while(n--) {
    int a, b;
    cin >> a >> b;
    m.insert({b,a});
    um[a] = b;
  }

  int l; cin >> l;
  while (l--) {
    string input; cin >> input;
    if (input == "add") {
      int a, b; cin >> a >> b;
      if (um.count(a)) {
        auto it = m.find({um[a],a});
        m.erase(it);
      }
      um[a] = b;
      m.insert({b,a});
    } else if (input == "recommend") {
      int a; cin >> a;
      if (a == 1) cout << (*m.rbegin()).second << '\n';
      else cout << (*m.begin()).second << '\n';
    } else {
      int a; cin >> a;
      auto it = m.find({um[a],a});
      m.erase(it);
      um.erase(a);
    }
  }
  return 0;
}
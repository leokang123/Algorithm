#include <bits/stdc++.h>
using namespace std;

int main (void) {
  cin.tie(nullptr)->sync_with_stdio(false);

  int n, k; cin >> n >> k;
  vector<pair<int,int>> m;
  multiset<int> bag;
  for (int i = 0 ; i < n ; i++) {
    int a, b; cin >> a >> b;
    m.push_back({b,a});
  }
  sort(m.begin(), m.end(), greater<pair<int,int>>());
  for (int i = 0 ; i < k ; i++) {
    int a; cin >> a;
    bag.insert(a);
  }
  long long res = 0;
  for (auto it = m.begin() ; it != m.end(); it++) {
    auto [p, w] = *it;
    auto bit = bag.lower_bound(w);
    if (bit == bag.end()) continue;
    res += p;
    bag.erase(bit);
  }
  cout << res << '\n';
  
  return 0;
}
#include <bits/stdc++.h>
using namespace std;

int main (void) {
  cin.tie(nullptr)->sync_with_stdio(false);

  int t; cin >> t;
  while (t--) {
    multiset<int> s;
    int n; cin >> n;
    while(n--) {
      char c;
      int num; cin >> c >> num;
      if (c == 'I') {
        s.insert(num);
      } else {
        if (s.size() == 0) continue;
        // if (num == 1) s.erase(s.rbegin());
        // erase에서 역방향 반복자는 허용하지 않는다고 한다
        // erase에 반복자가 아니라 값을 넣으면 해당 값을 모두 지운다 (이전에 바킹독씨가 했던말)
        if (num == 1) s.erase(prev(s.end()));
        else s.erase(s.begin());
      }
    }
    if (s.size() == 0) cout << "EMPTY" << '\n';
    else cout << *s.rbegin() << ' ' << *s.begin() << '\n';
  }

  return 0;
}
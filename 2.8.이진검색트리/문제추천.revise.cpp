#include <bits/stdc++.h>
using namespace std;


int main (void) {
  cin.tie(nullptr)->sync_with_stdio(false);
  int n; cin >> n;
  set<int> m[102];
  int um[1000002];
  while(n--) {
    int a, b;
    cin >> a >> b;
    m[b].insert(a);
    um[a] = b;
  }

  int l; cin >> l;
  while (l--) {
    string input; cin >> input;
    if (input == "add") {
      int a, b; cin >> a >> b;
      um[a] = b;
      m[b].insert(a);
    } else if (input == "recommend") {
      int a; cin >> a;
      if (a == 1){
        for (int i = 100 ; i >= 0 ; i--) {
          if (m[i].empty()) continue;
          cout << *(prev(m[i].end())) << '\n';
          break;
        }
      }
      else {
        for (int i = 0 ; i <= 100 ; i++) {
          if (m[i].empty()) continue;
          cout << *(m[i].begin()) << '\n';
          break;
        }
      }
    } else {
      int a; cin >> a;
      m[um[a]].erase(a);
    }
  }
  return 0;
}
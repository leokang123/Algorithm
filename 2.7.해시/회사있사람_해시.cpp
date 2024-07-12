#include <bits/stdc++.h>
using namespace std;

int main (void) {
  cin.tie(nullptr)->sync_with_stdio(false);
  unordered_set <string> s;
  int n; cin >> n;
  while (n--) {
    string a, b; cin >> a >> b;
    if (b == "enter") s.insert(a);
    else s.erase(a);
  }
  // unoreder_set이기 때문에 정렬하려면 다른 자료형에 담아야함 
  vector <string> ans(s.begin(), s.end());
  sort(ans.begin(), ans.end(), greater<string> ());
  for(auto i : ans) {
    cout << i << '\n';
  }
  return 0;
}
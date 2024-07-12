#include <bits/stdc++.h>
using namespace std;

int main (void) {
  cin.tie(nullptr)->sync_with_stdio(false);
  vector<string> s;
  int n; cin >> n;
  for (int i = 0 ; i < n ; i++) {
    string a, b; cin >> a >> b;
    s.push_back(a);
  }
  sort(s.rbegin(), s.rend());
  for(int i = 0 ; i < n ; i++) {
    if (i + 1 < n && s[i] == s[i+1]) {
      i++;
    }else {
      cout << s[i] << '\n';
    }
  }
  // for(int i = 0 ; i < n ;) {
  //   if (i + 1 < n && s[i] == s[i+1]) {
  //     i += 2;
  //   }else {
  //     cout << s[i++] << '\n';
  //   }
  // }
  return 0;
}
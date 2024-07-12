#include <bits/stdc++.h>
using namespace std;

int main (void) {
  cin.tie(nullptr)->sync_with_stdio(false);
  int n, m; cin >> n >> m;
  unordered_map<string, string> pton;
  for(int i = 1; i <= n ; i++) {
    string str; cin >> str;
    string index = to_string(i);
    pton[index] = str;
    pton[str] = index;
  }
  while(m--) {
    string str; cin >> str;
    cout << pton[str] << '\n';
  }
}
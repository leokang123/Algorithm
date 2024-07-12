#include <bits/stdc++.h>
using namespace std;

int main (void) {
  cin.tie(nullptr)->sync_with_stdio(false);
  int n, m; cin >> n >> m;
  unordered_map<string, int> pton;
  string ntop[100002];
  for(int i = 1; i <= n ; i++) {
    string str; cin >> str;
    ntop[i] = str;
    pton[str] = i;
  }
  while(m--) {
    string str; cin >> str;
    if (isdigit(str[0])) {
      cout << ntop[stoi(str)] << '\n';
    }
    else cout << pton[str] << '\n';
  }
}
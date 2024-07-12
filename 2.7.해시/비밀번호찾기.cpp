#include <bits/stdc++.h>
using namespace std;

unordered_map<string, string> pass;

int main (void) {
  cin.tie(nullptr)->sync_with_stdio(false);

  int n, m; cin >> n >> m;
  for (int i = 0 ; i < n ; i++) {
    string a,b; cin >> a >> b;
    pass[a] = b;
  }
  for(int i = 0 ; i < m ; i++) {
    string a; cin >> a ;
    cout << pass[a] << '\n';
  }

  return 0;
}
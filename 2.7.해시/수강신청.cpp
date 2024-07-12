#include <bits/stdc++.h>
using namespace std;

unordered_map <string ,int> s;
bool compare (pair<string, int>&a, pair<string,int>&b) {
  return a.second < b.second;
}
int main (void) {
  cin.tie(nullptr)->sync_with_stdio(false);

  int n, m; cin >> n >> m;
  for(int i = 0 ; i < m ; i++) {
    string str; cin >> str;
    s[str] = i;
  }
  vector<pair<string,int>> v(s.begin(), s.end());
  sort(v.begin(), v.end(), compare);

  int size = min(n,(int)v.size());
  
  for(int i = 0 ; i < size ; i++) {
    cout << v[i].first << '\n';
  }
  return 0;
}
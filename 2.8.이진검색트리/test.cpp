#include <bits/stdc++.h>
using namespace std;

int main (void) {
  map<int,int> m;
  m[1] = 1;
  m[2] = 4;
  m[6] = 10;
  m[10] = 123;
  auto it = m.lower_bound(0);
  cout << it->first << ' ' << it->second << '\n';
}
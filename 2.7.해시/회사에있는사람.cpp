/**
 * 그냥 하면 시간초과 발생 
 */

#include <bits/stdc++.h>
using namespace std;

int main (void) {
  cin.tie(nullptr)->sync_with_stdio(false);
  vector <string> e,l;
  int n; cin >> n ;
  while(n--) {
    string a, b; cin >> a >> b;
    if (b == "enter") e.push_back(a);
    else l.push_back(a);
  }
  sort(e.begin(), e.end());
  sort(l.begin(), l.end());
  vector<string> ans;
  for (auto it = e.begin() ; it != e.end();) {
    auto e_sit = upper_bound(it, e.end(), *it);
    auto e_eit = lower_bound(it, e.end(), *it);
    auto l_sit = upper_bound(l.begin(), l.end(), *it);
    auto l_eit = lower_bound(l.begin(), l.end(), *it);
    if (e_sit - e_eit > l_sit - l_eit) {
      ans.push_back(*it);
      it = e_sit; // erase로 반복자르 반환하게 되면 erase가 O(N)의 복잡도로 수행하는것때문에 시간초과가난다
      // 따라서 지우는것이 아닌 해당 반복자를 이동시켜주는 방식이 훨씬 좋다 (기억하기!) 
      // 그리고 반복자를 이용한 포문도 기억해 놓자 
    } else it++;
  }
  for(int i = ans.size() -1 ; i >= 0 ; i--) {
    cout << ans[i] << '\n';
  }
  return 0;
}
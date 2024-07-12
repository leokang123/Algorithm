#include <bits/stdc++.h>
using namespace std;

int main (void) {
  cin.tie(nullptr)->sync_with_stdio(false);

  int n; cin >> n;
  
  vector<pair<int,int>> v(n);
  multiset <int> ms;
  for (auto &i : v) cin >> i.first >> i.second;
  sort(v.begin(), v.end(), greater<pair<int,int>>());
  for (auto[a, b] : v) {
    auto it = ms.lower_bound(b);
    if (it == ms.begin() || ms.empty()) {
      ms.insert(1);
      continue;
    }
    it = prev(it);
    int val = *it + 1;
    // 반복자를 사용할때 insert로 인해 내부구조가 바뀌어 반복자 무효화가 생길수 있다고한다
    // 따라서 반복자의 값을 받아놓고 수정,삭제,갱신을 하는것이 좋다고 한다. 
    ms.erase(it);
    ms.insert(val);
  }
  cout << ms.size() << '\n';
  return 0;
}
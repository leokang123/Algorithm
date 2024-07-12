#include <bits/stdc++.h>
using namespace std;
typedef long long ll; 
ll p, q;
unordered_map<ll, ll> mp;
ll recur(ll n) {
  /**
   * 어떤 요소를 찾고 그 값을 사용할때는 find가 더 좋지만 
   * 존재 유무만 따질때는 count를 사용하는것이 좋다고 함 
   */
  // if(mp.find(n) != mp.end()) return mp[n];
  if (mp.count(n)) return mp[n];
  if (n == 0) return 1;
  mp[n] = recur(n / p) + recur(n / q);
  return mp[n];
}
int main(void) {
  cin.tie(nullptr)->sync_with_stdio(false);
  ll n; cin >> n;
  cin >> p >> q;
  ll result = recur(n);
  cout << result << '\n';
  return 0;
}
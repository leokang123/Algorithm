#include <bits/stdc++.h>
using namespace std;

int main (void) {
  cin.tie(nullptr)->sync_with_stdio(false);

  set<int> allSet[102];
  set<int> levSet[102][102];
  unordered_map<int, pair<int,int>> pro2lev;

  int n ; cin >> n;
  while(n--) {
    int a, b, c; cin >> a >> b >> c;
    pro2lev[a] = {b,c};
    allSet[b].insert(a);
    levSet[c][b].insert(a);
  }

  int l; cin >> l;
  while(l--) {
    string input; cin >> input;
    if (input == "recommend") {
      int a,b; cin >> a >> b;
      if (b == 1) {
        for (int i = 100; i>= 0 ;i--) {
          if (levSet[a][i].empty()) continue;
          cout << *(prev(levSet[a][i].end())) << '\n';
          break;
        }
      }
      else {
        for (int i = 0; i<= 100 ;i++) {
          if (levSet[a][i].empty()) continue;
          cout << *(levSet[a][i].begin()) << '\n';
          break;
        }
      }
    } else if (input == "recommend2") {
      int b; cin >> b;
      if (b == 1) {
        for (int i = 100; i>= 0 ;i--) {
          if (allSet[i].empty()) continue;
          cout << *(prev(allSet[i].end())) << '\n';
          break;
        }
      }
      else {
        for (int i = 0; i<= 100 ;i++) {
          if (allSet[i].empty()) continue;
          cout << *(allSet[i].begin()) << '\n';
          break;
        }
      }
    } else if (input == "recommend3") {
      int a, b; cin >> a >> b;
      int iscout = 0;
      if (a == 1) {
        for (int i = b; i<= 100 ;i++) {
          if (allSet[i].empty()) continue;
          iscout = 1;
          cout << *(allSet[i].begin()) << '\n';
          break;
        }
        if (!iscout) cout << -1 << '\n';
      } else {
        for (int i = b-1 ; i>= 0 ;i--) {
          if (allSet[i].empty()) continue;
          iscout = 1;
          cout << *(prev(allSet[i].end())) << '\n';
          break;
        }
        if (!iscout) cout << -1 << '\n';
      }
    } else if (input == "add") {
      int a,b,c; cin >> a >> b >> c; // p l g
      allSet[b].insert(a);
      levSet[c][b].insert(a);
      pro2lev[a] = {b,c};
    } else {
      int a; cin >> a;
      auto [l,g] = pro2lev[a];
      allSet[l].erase(a);
      levSet[g][l].erase(a);
    }
  }
  return 0;
}
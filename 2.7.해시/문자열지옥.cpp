#include <bits/stdc++.h>
using namespace std;

int dy[8] = {1, 1, 0,-1,-1,-1, 0, 1}; // 열 
int dx[8] = {0,-1,-1,-1, 0, 1, 1, 1}; // 행
// char board[11][11] = {0,};
string board[11];
int n, m, k;
unordered_map<string,int> mp;

void findAll() {
  for (int i = 0 ; i < n ; i++) {
    for(int j = 0 ; j < m ; j++) {
      queue<tuple<int, int, string>> q;
      q.push({i,j,string(1,board[i][j])});
      mp[string(1,board[i][j])]++;
      while(!q.empty()) {
        auto [cx, cy, ctr] = q.front(); q.pop();
        if (ctr.length() == 5) break;
        for (int k = 0 ; k < 8 ; k++) {
          int nx = (cx + dx[k] + n) % n;
          int ny = (cy + dy[k] + m) % m;
          string ntr = ctr + board[nx][ny];
          mp[ntr]++;
          q.push({nx,ny,ntr});
        }
      }
    }
  }
}
int main (void) {
  cin.tie(nullptr)->sync_with_stdio(false);
  cin >> n >> m >> k;
  for(int i = 0 ; i < n ; i++) {
    cin >> board[i];
  }

  findAll();

  for (int i = 0 ;i < k ; i++) {
    string a; cin >> a;
    cout << mp[a] << '\n';
  }
  return 0;
}

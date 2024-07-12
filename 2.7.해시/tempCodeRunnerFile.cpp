#include <bits/stdc++.h>
using namespace std;

int dy[8] = {1, 1, 0,-1,-1,-1, 0, 1}; // 열 
int dx[8] = {0,-1,-1,-1, 0, 1, 1, 1}; // 행
// char board[11][11] = {0,};
string board[100];
int n, m, k;
unordered_map<string,int> mp;

void func(int x, int y) {
  queue<tuple<int, int, string>> q;
  string s ;
  s +=  board[x][y];
  q.push({x,y, s});
  while(!q.empty()) {
    int cx, cy;
    string ctr;
    tie(cx,cy,ctr) = q.front(); q.pop();
    // auto [cx, cy, ctr] = q.front(); q.pop();
    // if (ctr.length() == k) continue;
    
    for (int k = 0 ; k < 8 ; k++) {
      int nx = (cx + dx[k] + n) % n;
      int ny = (cy + dy[k] + m) % m;
      string ntr = ctr + board[nx][ny];
      mp[ntr] ++;
      if(ntr.length() < k) q.push({nx,ny,ntr});
    }
  }
}

int main (void) {
  cin.tie(nullptr)->sync_with_stdio(false);
  cin >> n >> m >> k;
  for(int i = 0 ; i < n ; i++) {
    cin >> board[i];
  }
  for (int i = 0 ; i < n ; i++) {
    for(int j = 0 ; j < m ; j++) func(i, j);
  }
  for (int i = 0 ;i < k ; i++) {
    string a; cin >> a;
    cout << mp[a] << '\n';
  }
  return 0;
}

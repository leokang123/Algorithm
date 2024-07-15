#include <bits/stdc++.h>
using namespace std;
// 동 북 서 남 
int dy[4] = {0,-1,0,1};
int dx[4] = {1,0,-1,0};
int n, m;
int board[501][501];
int mVal = 0;

void check(int y, int x, int sum, int cnt) {
  for (int i = 0 ; i < 4 ; i++) {
    int ny = y + dy[i];
    int nx = x + dx[i];
    int ncnt = cnt+1;
    if (ny < 0 || nx < 0 || ny >= n || nx >= m) continue;
    if (board[ny][nx] == -1) continue;
    if (ncnt == 4) {
      mVal = max(mVal, sum + board[y][x]);
      return ;
    }
    int tmp = board[y][x];
    board[y][x] = -1;
    check(ny,nx,sum+tmp,cnt+1);
    board[y][x] = tmp;
  }
  return ;
}

void checkF(int y, int x) {
  int a = board[y][x];
  for (int i = 0 ; i < 4; i++) {
    int sum = a;
    for (int j = 0 ; j < 4 ; j++) {
      if (j == i) continue;
      int ny = y + dy[j];
      int nx = x + dx[j];
      if (ny < 0 || nx < 0 || ny >= n || nx >= m) continue;
      sum += board[ny][nx];
    }
    mVal = max(mVal, sum);
  }
}

int main (void) {
  cin.tie(nullptr)->sync_with_stdio(false);
  cin >> n >> m;
  for (int i = 0 ; i < n ; i++) {
    for (int j = 0 ; j < m ; j++) cin >> board[i][j];
  }
  for (int i = 0 ; i < n ; i++) {
    for (int j = 0 ; j < m ; j++) {
      check(i,j,0,0);
      checkF(i,j);
    }
  }
  cout << mVal << '\n';
  return 0;

}
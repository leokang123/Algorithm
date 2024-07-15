#include <bits/stdc++.h>
using namespace std;

// 반시계 북 서 남 동 (y,x)꼴임 
int dy[4] = {-1,0,1,0};  // 행 
int dx[4] = {0,-1,0,1};  // 열 
int n, m; 
int board[55][55];

int dir(int a) {
  switch (a) {
  case 0:
    return 0;
  case 1:
    return 3;
  case 2:
    return 2;
  case 3:
    return 1;
  }
}
void printB() {
  cout << '\n';
  for (int i = 0 ; i < n ; i++) {
    for (int j = 0 ; j < m ; j++) {
      if (board[i][j] < 10) cout << ' ';
      cout << board[i][j] << ' ' ;
    }
    cout << '\n';
  }
}
int turnLeft(int a) {
  return (a+1) % 4;
}

int turnAround(int a, int y, int x) {
  int cur = a;
  for (int i = 0 ; i < 4; i++) {
    cur = turnLeft(cur);
    int cy = y + dy[cur];
    int cx = x + dx[cur];
    if (cx < 0 || cy < 0 || cx >= m || cy >= n) continue;
    if (board[cy][cx] == 0) return cur;
  }
  return -1;
}

int main (void) {
  cin.tie(nullptr)->sync_with_stdio(false);
  cin >> n >> m;
  int sy,sx,sd; cin >> sy >> sx >> sd;
  sd = dir(sd);
  // 이런식으로도 2차원 벡터 초기화 할수도 있다는거
  for (int i = 0 ; i < n ; i++) {
    for (int j = 0 ; j < m ; j++) cin >> board[i][j];
  }
  queue<pair<int,int>> q;
  q.push({sy,sx});
  int dis = 1;
  while (!q.empty()) {
    auto [cy, cx] = q.front(); q.pop();
    board[cy][cx] = 2;

    int nd = turnAround(sd,cy,cx);
    if (nd == -1) {
      cy += dy[(sd+2)%4];
      cx += dx[(sd+2)%4];
      if (board[cy][cx] == 1) break;
      q.push({cy,cx});
      continue;
    }
    dis++;
    cy += dy[nd];
    cx += dx[nd];
    sd = nd;
    q.push({cy,cx});
  }
  cout << dis << '\n';
  return 0;
}
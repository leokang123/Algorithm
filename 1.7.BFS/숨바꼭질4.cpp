#include <bits/stdc++.h>
using namespace std;

#define MAX 100001 
#define X first 
#define Y second 

int vis[MAX]; // 이전 경로를 기록하면서 와야함 초기값 -1 로 두고 
int arr2[MAX];

int main(void) {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int n, m;
    cin >> n >> m;
    fill(vis, vis + MAX, -1);
    vis[n] = n; // 이후로 부턴 이전값을 계속 갱신 
    // {위치, 시간}
    queue<pair<int, int>> Q;
    Q.push({n,0});

    // 예외처리 
    if(n == m) {
        cout << 0 << '\n';
        cout << n << '\n'; 
        return 0;
    }
    
    while(!Q.empty()) {
        pair<int, int>  cur = Q.front(); Q.pop();
        for(int nx : {cur.X-1,cur.X+1,cur.X*2}) {
            int time = cur.Y;
            if(nx < 0 || nx >= MAX + 1) continue;
            if(vis[nx] != -1 ) continue;
            if(nx == m) {
                vis[nx] = cur.X;
                cout << ++time << '\n';
                int num = time + 1;
                while(num--) {
                    arr2[num] = nx;
                    nx = vis[nx];
                }
                for(int i = 0 ; i < time + 1 ; i++) {
                    cout << arr2[i] << ' ';
                }
            }
            time++;
            vis[nx] = cur.X;
            Q.push({nx,time});
        }
    }
    
    return 0;

}
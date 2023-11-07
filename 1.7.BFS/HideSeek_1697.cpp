#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second 
int dist[100002];
int n,m;
// 1차원에서의 BFS인데, 결론은 최단거리인거 같다 
// 완전 탐색을 해야하는 경우에 거리가 중요한지(BFS), 경로가 중요한지(DFS)를 구별해서 BFS를 적용할지 DFS를 적용할지 고민해야한다 
int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    fill(dist,dist+100001,-1);
    cin >> n >> m;
    queue<int> Q;
    dist[n]++;
    Q.push(n);
    while(!Q.empty())
    {
        int cur = Q.front(); Q.pop();
        for(int nxt : {cur-1,cur+1,cur*2}){
            // 보통 x,y 는 행,열 임 
            if(nxt < 0 || nxt > 100000) continue;
            if(dist[nxt] != -1) continue;
            dist[nxt] = dist[cur] + 1;
            Q.push(nxt);
        }
    }
    cout << dist[m]<<'\n';
}
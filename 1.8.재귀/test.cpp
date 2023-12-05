#include <bits/stdc++.h>
using namespace std;
#define MAX 100001
int dist[MAX];
int start1,end1;

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> start1 >> end1;
    fill(dist,dist+MAX,-1);
    queue<int> Q;
    Q.push(start1);
    dist[start1] = 0;

    while(dist[end1] == -1){
        int top1 = Q.front(); Q.pop();
        for(int nxt : {top1*2, top1-1,top1+1}){
            if(nxt<0 || nxt >= MAX) continue;
            if(dist[nxt] >= 0) continue;
            if(nxt == top1 * 2) dist[nxt] = dist[top1];
            else dist[nxt] = dist[top1] + 1;
            Q.push(nxt);
        }   
    }
    cout << dist[end1] <<'\n';

}   
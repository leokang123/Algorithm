//시간 초과 
// map쓰면 시간초과 나옴 

#include <bits/stdc++.h>
using namespace std;
#define MAX 100002
#define X first
#define Y second 
int vis[MAX]; // 스택안에 들어가있는 인덱스 
int notvis[MAX]; 
int sum;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T; cin>> T;
    while(T--){
        int num;cin >> num;
        for(int i = 1; i<=num; i++){
             vis[i] = 0;
             notvis[i] = 0;
        }
        sum = 0;
        map<int,int> map;
        stack<pair<int, int> > S;
        for(int i = 1;i<=num;i++){
            int a; cin >> a;
            map[i] = a;
            if(i == map[i]){
                notvis[i] = 1; // 앞으로 방문할 필요없는 거  표시 
                map[i] = 0; 
            }
        }
        pair<int, int> cur;
        for(int i = 1;i <=num;i++){
            if(notvis[i] == 1) continue;
            cur = {i,map[i]};
            S.push(cur);
            vis[cur.X] = 1; 
            while(!S.empty()){
                if(notvis[cur.Y] == 1){
                    while(!S.empty()){
                        vis[S.top().X] = 0;
                        notvis[S.top().X] = 1;
                        S.pop();
                    }
                    break;
                }
                if(vis[cur.Y] == 1){ // 사이클이 생겼다는 뜻 
                    int endnum = cur.Y; // 사이클이 생긴 인덱스 저장 
                    while(cur.X != endnum){
                        map[cur.X] = 0; // 0 이 사이클이라는 뜻
                        vis[cur.X] = 0;
                        notvis[cur.X] = 1; // 더이상 방문안해도 된다는 뜻
                        S.pop();
                        if(!S.empty()) cur = S.top();
                    }
                    map[cur.X] = 0; // 0 이 사이클이라는 뜻
                    vis[cur.X] = 0;
                    notvis[cur.X] = 1; // 더이상 방문안해도 된다는 뜻
                    S.pop();
                    while(!S.empty()){
                        vis[S.top().X] = 0;
                        notvis[S.top().X] = 1;
                        S.pop();
                    }
                    break;
                }
                cur = {cur.Y,map[cur.Y]};
                vis[cur.X] = 1;
                S.push(cur);
            }
        }
        for(int i = 1;i<=num;i++){
            if(map[i] == 0) continue;
            sum++;
        }
        cout << sum <<'\n';
    }
}

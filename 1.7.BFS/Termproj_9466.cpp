
#include <bits/stdc++.h>
using namespace std;
#define MAX 100002
#define X first
#define Y second 
int board[MAX];
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
        stack<pair<int, int> > S;
        for(int i = 1;i<=num;i++){
            cin >> board[i];
            if(i == board[i]){
                notvis[i] = 1; // 앞으로 방문할 필요없는 거  표시 
                board[i] = 0; 
            }
        }
        pair<int, int> cur;
        for(int i = 1;i <=num;i++){
            if(notvis[i] == 1) continue;
            cur = {i,board[i]};
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
                        board[cur.X] = 0; // 0 이 사이클이라는 뜻
                        vis[cur.X] = 0;
                        notvis[cur.X] = 1; // 더이상 방문안해도 된다는 뜻
                        S.pop();
                        if(!S.empty()) cur = S.top();
                    }
                    board[cur.X] = 0; // 0 이 사이클이라는 뜻
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
                cur = {cur.Y,board[cur.Y]};
                vis[cur.X] = 1;
                S.push(cur);
            }
        }
        for(int i = 1;i<=num;i++){
            if(board[i] == 0) continue;
            sum++;
        }
        cout << sum <<'\n';
    }
}
//     while(T--){
//         int num;cin>> num;
//         for(int i = 1; i<= num;i++) vis[i] = 0;
//         sum = 0;
//         map<int, int> map;
//         stack<pair<int, int>> S;
//         for(int i = 1;i<=num;i++){
//             int a; cin >> a;
//             map.insert({i,a});
//             if(i == a){ 
//                 vis[i] = 1;
//                 map.erase(i);
//             }
//         }
//         pair<int, int> cur;
//         for(int i = 1;i <=num;i++){
//             if(notvis[i] == 1 && vis[i] == 1) continue;
//             cur = {i,map[i]};
//             S.push(cur);
//             vis[cur.X] = 1;
//             pair<int,int> top1 = S.top();
//             while(!S.empty()){
//                 cout << "1push"<< top1.X <<','<<top1.Y<<'\n';
//                 if(notvis[cur.Y] == 1) break;
//                 if(map[cur.Y] == 0){
//                     while(!S.empty()){
//                         top1 = S.top();
//                         cout << "pop"<< top1.X <<','<<top1.Y<<'\n';
//                         S.pop();
//                     } 
//                     notvis[cur.Y] = 1;
//                     break;
//                 }
//                 cur = {cur.Y,map[cur.Y]};
//                 S.push(cur);
//                 vis[cur.X] = 1;
//                 top1 = S.top();
//                 cout << "2push"<< top1.X <<','<<top1.Y<<'\n';
//                 if(vis[cur.Y] == 1){
//                     while(vis[cur.Y] != 1){
//                         pair<int,int> top1 = S.top();
//                         cout << "pop "<< top1.X <<','<<top1.Y<<'\n';
//                         map.erase(top1.X);
//                         S.pop();
//                     }
//                     break;
//                 }
//             }
//         }
//         for(int i =1;i<=num;i++){
//             if(map[i] == 0) continue;
//             sum++;
//         }
//         cout << sum <<' '<<map[3];
//     }
// }
// int main(void)
// {
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);
//     int T;cin >> T;
    
//     while(T--){
//         int num; cin >> num;
//         for(int i = 1;i<=num;i++) vis[i] = 0;
//         sum = 0;
//         map<int, int> map;
//         queue<pair<int, int>> q;
//         queue<int> Q2;
//         for(int i = 1; i<= num;i++){
//             int a; cin >> a;
//             map.insert({i,a});
//             if(i == map[i]){
//                 vis[i] = 1;
//             }
//         }
//         pair<int,int > cur;
//         pair<int, int> tail;

//         for(int i = 1;i <= num+1; i++){
//             while(!q.empty()) {
//                 if(cur.Y == tail.X){
//                     int er = q.front().X;q.pop();
//                     Q2.push(er);
//                 }else{
//                 int key = q.front().X; q.pop();
//                 vis[key] = 0;
//                 }
//             }

//             cur = {i,map[i]};
//             q.push(cur);
//             tail = {i,map[i]};
//             vis[cur.X] = 1;
//             while(!q.empty())
//             {
//                 if(vis[cur.Y] == 1) break;
//                 if(map[cur.Y] == 0) break;
//                 if(cur.Y == tail.X) break;
//                 if(vis[cur.X] == 1)
//                 cur = {cur.Y,map[cur.Y]};
//                 q.push(cur);vis[cur.X] = 1;
//             }
//         }

//         cout << num - Q2.size() << '\n';
                

//     }
// }

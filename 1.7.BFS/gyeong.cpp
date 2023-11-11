// #include <iostream>
// #include <array>
// #include <queue>
// #include <string.h>

// using namespace std;

// int board[100005];
// bool vis[100005];
// bool cycle[100005];
// bool notcy[100005];

// int t,m,n,num,cnt;

// int check(int idx){ //cycle 체크
//     if(notcy[idx] == 1) return 0;
//     queue<int> a;
//     vis[idx] = true;
//     int cur = idx;
//     // cout<<1<<' '<<idx<<' ' << cur <<'\n';
//     a.push(cur);
//     while(!a.empty()){
//         cur = board[cur];
//         if(!vis[cur]){
//             // cout<<2<<' '<<idx<<' ' << cur <<'\n';
//             vis[cur] = true;
//             a.push(cur);
//         }
//         else{
//             if(notcy[cur] == 1 || cycle[cur] == 1){
//                 while(!a.empty()){
//                     int front1 = a.front();a.pop();
//                     notcy[front1] = 1;
//                     // cout << cur<<front1<<'\n';
//                 }
//                 return 0;
//             }
//             // cout<<3<<' '<<idx<<' ' << cur <<'\n';
//             if(!cycle[cur]){
//                 while(idx != cur){
//                     notcy[idx] = 1;
//                     a.pop();
//                     if(!a.empty()) idx = a.front();
//                     // if(idx == 3) cout<<4<<' '<<idx<<' ' << cur <<'\n';
//                 }
//                 while(!a.empty()){
//                     int front1 = a.front();a.pop();
//                     cycle[front1] = 1;
//                     // cout << front1<<'\n';
//                     num++;
//                 }
//             }
//             return 0;
//         }
//     }
//     return 0 ;
// }
// int main(){
//     ios_base::sync_with_stdio(false);
//     cin.tie(nullptr);
//     cin >> t;
//     for(int k=0;k<t;k++){
//         cin >> n;
//         num = 0;
//         memset(vis,0,sizeof(vis));
//         memset(cycle,0,sizeof(cycle));
//         memset(notcy,0,sizeof(notcy));
//         for(int i=1;i<=n;i++){
//             cin >> board[i];
//         }
//         for(int i=1;i<=n;i++){
//             if(!cycle[i]){
//                 check(i);
//             }
//         }
//         cout << n-num<<'\n';
        
        
//     }
//     return 0;
// }
#include <iostream>
#include <array>
#include <queue>
#include <string.h>

using namespace std;

int board[100005];
bool vis2[100005];
bool cycle[100005];
bool notcy[100005];

int t,m,n,num,cnt;

void check(int idx){ //cycle 체크
    if(notcy[idx] == 1) return ;
    queue<int> a;
    vis2[idx] = true;
    int cur = idx;
    a.push(idx);
    while(!a.empty()){
        cur = board[cur];
        if(notcy[cur] == 1 || cycle[cur] == 1){
            while(!a.empty()){
                notcy[a.front()] = 1;
                a.pop();
            }
            return;
        }
        if(!vis2[cur]){
            vis2[cur] = true;
            a.push(cur);
            continue;
        }else if(!cycle[cur]){
            while(idx != cur){
                notcy[idx] = 1;
                a.pop();
                idx = a.front();
            } 
            while(!a.empty()){
                cycle[a.front()] = 1;
                a.pop();
                num++;
            }
        }else return;
    }
    return ;
}
int main(){
    ios_base::sync_with_stdio(false);
   cin.tie(NULL);
    cin >> t;
    for(int k=0;k<t;k++){
        cin >> n;
        num = 0;
        memset(notcy,0,sizeof(notcy));
        memset(vis2,0,sizeof(vis2));
        memset(cycle,0,sizeof(cycle));
        for(int i=1;i<=n;i++){
            cin >> board[i];
        }
        for(int i=1;i<=n;i++){
            if(!cycle[i]){
                check(i);
            }
        }
        cout << n-num<<'\n';
        
        
    }
    return 0;
}
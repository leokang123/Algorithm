#include <bits/stdc++.h>
using namespace std; 
#define MAX 50001
int board[MAX];

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int num,how; cin >> num >> how;
    deque<int> Q1;
    for(int i = 1; i <= num; i++) Q1.push_back(i);
    int pop_num = 0;
    cout <<'<';
    while(!Q1.empty()){
        int Q_front = Q1.front();Q1.pop_front();
        pop_num++;
        if(pop_num % how == 0){
            if(Q1.size() >= 1) cout << Q_front<<','<<' ';
            else if(Q1.size() == 0)cout << Q_front<<'>'<<'\n';
            pop_num = 0;
        }   
        else Q1.push_back(Q_front);
    }
}
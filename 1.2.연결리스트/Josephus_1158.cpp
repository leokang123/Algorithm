#include <bits/stdc++.h>
using namespace std; 
#define MAX 50001
int board[MAX];

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int num;
    int how; cin >> num >> how;
    int total = num;
    for(int i = 1;i <= num;i++) board[i] = i;
    int iter_num = 1; // 배열 순회를 위한 인덱스
    int cor_num = iter_num; // 정답 순회를 위한 인덱스 
    cout << '<';
    while(total){
        if(iter_num > num) {
            iter_num = iter_num % num;
        }
        if(board[iter_num] == 0){
            iter_num++;
            continue;
        }
        if(cor_num % how == 0){
            int pop = iter_num;
            if(total == 1) cout << board[pop]<<'>'<<'\n';
            if(total > 1) cout << board[pop]<<','<<' ';
            board[pop] = 0;
            total--;
            iter_num++;
            cor_num = 1;
            continue;
        }
        iter_num++;
        cor_num++;
    }
}
#include <bits/stdc++.h>    
using namespace std;
#define MAX 2200
// int num1;
// int num2;
// int num3;
int result[3];
int init_N;
int board[MAX][MAX];
void numPaper(int N,int a,int b){
    int ini = board[a][b];
    int mult = N/3;
    for(int i = a;i < a+N;i++){
        for(int j = b; j < b+N; j++){
            if(board[i][j] != ini){
                numPaper(N/3,a,b);
                numPaper(N/3,a+mult,b);
                numPaper(N/3,a,b+mult);
                numPaper(N/3,a+mult,b+mult);
                numPaper(N/3,a+mult*2,b); 
                numPaper(N/3,a,b+mult*2);
                numPaper(N/3,a+mult*2,b+mult);
                numPaper(N/3,a+mult,b+mult*2);
                numPaper(N/3,a+mult*2,b+mult*2);
                return;
            }
        }
    }
    result[ini+1] += 1;
    return;
}

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int num;cin >> num;
    init_N = num;
    for(int i = 0;i< init_N;i++){
        for(int j = 0; j < init_N ; j++){
            cin >> board[i][j];
        }
    }
    numPaper(init_N,0,0);
    cout << result[0] <<'\n';
    cout << result[1] <<'\n';
    cout << result[2] <<'\n';
}

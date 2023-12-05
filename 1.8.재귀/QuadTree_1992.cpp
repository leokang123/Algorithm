#include <bits/stdc++.h>    
using namespace std;
#define MAX 2200
// int num1;
// int num2;
// int num3;
int result[3];
int init_N;
string board[MAX];
void numPaper(int N,int a,int b){
    char ini = board[a][b];
    int mult = N/2;
    for(int i = a;i < a+N;i++){
        for(int j = b; j < b+N; j++){
            if(board[i][j] != ini){
                cout << '(';
                numPaper(mult,a,b);
                numPaper(mult,a,b+mult);
                numPaper(mult,a+mult,b);
                numPaper(mult,a+mult,b+mult);
                cout << ')';
                return;
            }
        }
    }
    cout << ini;
    result[ini+1] += 1;
    return;
}

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int num;cin >> num;
    init_N = num;
    for(int i = 0;i< init_N;i++) cin >> board[i];
    numPaper(init_N,0,0);
    cout <<'\n';
}

#include <bits/stdc++.h>    
using namespace std;
#define MAX 6500
char str[MAX][MAX];

void star(int N,int a,int b,char c){
    int half = N/3;
    if(N==1){
        str[a][b] = c;
        return;
    }
    star(half,a,b,c);
    star(half,a,b+half,c);
    star(half,a,b+half*2,c);
    star(half,a+half,b,c);
    star(half,a+half,b+half,' ');
    star(half,a+half,b+half*2,c);
    star(half,a+half*2,b,c);
    star(half,a+half*2,b+half,c);
    star(half,a+half*2,b+half*2,c);
}

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int num;cin >> num;
    star(num,0,0,'*');
    for(int i = 0 ; i < num ; i++){
        for(int j = 0; j < num ; j++){
            cout<<str[i][j];
        }
        cout <<'\n';
    }
}
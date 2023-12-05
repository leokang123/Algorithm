#include <bits/stdc++.h>    
using namespace std;
#define MAX 6500
char str[MAX][MAX];

void star(int N,int a,int b,char c){
    int half = N / 2;
    if(N==3){
        str[a][b] = ' ';
        str[a][b+1] = ' ';
        str[a][b+2] = c;
        str[a][b+3] = ' ';
        str[a][b+4] = ' ';
        str[a][b+5] = ' ';

        str[a+1][b] = ' ';
        str[a+1][b+1] = c;
        str[a+1][b+2] = ' ';
        str[a+1][b+3] = c;
        str[a+1][b+4] = ' ';
        str[a+1][b+5] = ' ';

        str[a+2][b] = c;
        str[a+2][b+1] = c;
        str[a+2][b+2] = c;
        str[a+2][b+3] = c;
        str[a+2][b+4] = c;
        str[a+2][b+5] = ' ';
        return ;
    }
    //1
    star(half,a,b,' ');
    star(half,a,b+half,c);
    star(half,a,b+half+N,' ');
    star(half,a+half,b,c);
    star(half,a+half,b+N,c);
    
}

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int num;cin >> num;
    star(num,0,0,'*');
    for(int i = 0 ; i < num ; i++){
        for(int j = 0; j < num*2 ; j++){
            cout<<str[i][j];
        }
        cout <<'\n';
    }
}
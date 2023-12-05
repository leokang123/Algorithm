#include <bits/stdc++.h>
using namespace std;
#define MAX 15
int count1;
int total;
int board[MAX][MAX];
int N;
int close1 = 0;
void makediagonal(int x, int y){
    count1++;
    for(int s= 0; s < N; s++){
        board[x][s] += 1;
        board[s][y] += 1;
        int curx = s + x;
        int cury = s + y;
        if(curx<0||cury<0||curx>=N||cury>=N) continue;
        board[curx][cury] += 1;
    }
    for(int s= 0; s < N; s++){
        int curx = s + x;
        int cury = y - s;
        if(curx<0||cury<0||curx>=N||cury>=N) continue;
        board[curx][cury] += 1;
    }
    for(int s= 0; s < N; s++){
        int curx = x - s;
        int cury = s + y;
        if(curx<0||cury<0||curx>=N||cury>=N) continue;
        board[curx][cury] += 1;
    }
    for(int s= 0; s < N; s++){
        int curx = x - s ;
        int cury = y - s;
        if(curx<0||cury<0||curx>=N||cury>=N) continue;
        board[curx][cury] += 1;
    }
}

void closediagonol(int x,int y){
    count1--;
    for(int s= 0; s < N; s++){
        board[x][s] -= 1;
        board[s][y] -= 1;
        int curx = s + x;
        int cury = s + y;
        if(curx<0||cury<0||curx>=N||cury>=N) continue;
        board[curx][cury] -= 1;
    }
    for(int s= 0; s < N; s++){
        int curx = s + x;
        int cury = y - s;
        if(curx<0||cury<0||curx>=N||cury>=N) continue;
        board[curx][cury] -= 1;
    }
    for(int s= 0; s < N; s++){
        int curx = x - s;
        int cury = s + y;
        if(curx<0||cury<0||curx>=N||cury>=N) continue;
        board[curx][cury] -= 1;
    }
    for(int s= 0; s < N; s++){
        int curx = x - s;
        int cury = y - s ;
        if(curx<0||cury<0||curx>=N||cury>=N) continue;
        board[curx][cury] -= 1;
    }
}

void func1(int k ){
    if(count1 == N){
        total++;
        return;
    }
    for(int j = 0 ; j < N;j++){
        if(!board[k][j]){
            makediagonal(k,j);
            func1(k+1);
            closediagonol(k,j);
        }
    }
}

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N;
    func1(0);
    cout << total<<'\n';
}
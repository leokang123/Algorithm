#include <bits/stdc++.h>
using namespace std; 
#define MAX 20 
int board[MAX][MAX];
int row[4] = {4,1,3,6};
int col[4] = {2,1,5,6};
int dice[7]; // 주사위 번호 
int N, M ; 
int xpos,ypos; 

void movingFunc(int mod) {
    int tempt = 0;
    if (mod == 1) {
        // 동쪽 
        ypos += 1;
        tempt = row[3];
        for(int i = 3 ; i >=1 ; i--) row[i] = row[i-1];
        row[0] = tempt;
        col[1] = row[1];
        col[3] = row[3];
    }
    else if (mod == 2) {
        // 서쪽 
        ypos -= 1;
        tempt = row[0];
        for(int i = 0 ; i < 3 ; i++) row[i] = row[i+1];
        row[3] = tempt;
        col[1] = row[1];
        col[3] = row[3];
    }
    else if (mod == 3) {
        // 북쪽
        xpos -= 1;
        tempt = col[0];
        for(int i = 0 ; i < 3 ; i++) col[i] = col[i+1];
        col[3] = tempt;
        row[1] = col[1];
        row[3] = col[3];
    }
    else {
        // 남쪽 
        xpos += 1;
        tempt = col[3];
        for(int i = 3 ; i >=1 ; i--) col[i] = col[i-1];
        col[0] = tempt;
        row[1] = col[1];
        row[3] = col[3];
    }
}

int checkSpot(int mod) {
    int isOver = 0;
    if ( mod == 1 ) {
        if (ypos + 1 >= M) {
            isOver = 1;
        }
    }
    if ( mod == 2 ) {
        if (ypos - 1 < 0) {
            isOver = 1;
        }
    }
    if ( mod == 3 ) {
        if (xpos - 1 < 0) {
            isOver = 1;
        }
    }
    if ( mod == 4 ) {
        if (xpos + 1 >= N ) {
            isOver = 1;
        }
    }
    return isOver;
}

void drawDice(void) {
    int num = 0 ;
    if(board[xpos][ypos] != 0){
        dice[row[3]] = board[xpos][ypos];
        board[xpos][ypos] = 0;
    }
    else {
        board[xpos][ypos] = dice[row[3]];
    }
}

int main(void) {
    cin >> N >> M ;
    cin >> xpos >> ypos;
    int K ; cin >> K;
    for (int i = 0 ; i < N ; i++) {
        for (int j = 0 ; j < M ; j++) {
            cin >> board[i][j];
        }
    }
    while(K--) {
        int mod; 
        cin >> mod;
        if (!checkSpot(mod)) {
            movingFunc(mod);
            drawDice();
            cout << dice[row[1]] << '\n';
        }
        
    }
}
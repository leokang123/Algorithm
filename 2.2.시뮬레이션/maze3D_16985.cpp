#include <bits/stdc++.h>
using namespace std; 

#define X get <1> (cur)
#define Y get <2> (cur) 
#define Z get <0> (cur)
#define SIZE 5
int board[SIZE][SIZE][SIZE];
int newBoard[SIZE][SIZE][SIZE];
int distB[SIZE][SIZE][SIZE];
int check[SIZE];
int dx[6] = {0,0,1,0,-1,0};
int dy[6] = {0,0,0,1,0,-1};
int dz[6] = {1,-1,0,0,0,0};
int BFS();
int min1 = 200;

void resetDist() {
    for(int i = 0 ; i < SIZE ; i++ ){
        for(int j = 0 ; j < SIZE ; j++) fill(distB[i][j], distB[i][j] + SIZE, -1);
    }
    // memset(distB,-1,sizeof(distB));
}

void turnNinty(int n,int level, int mod) {
    if (mod == 0) {
        for(int i = 0 ; i < 5 ; i++) {
            for(int j = 0 ; j < 5; j++){
                newBoard[level][i][j] = board[n][i][j];
            }
        }
    }
    else if(mod == 1) { // 90 도 
        for(int i = 0 ; i < 5 ; i++) {
            for(int j = 0 ; j < 5; j++){
                newBoard[level][j][SIZE-1-i] = board[n][i][j];
            }
        }
    }
    else if (mod == 2) {
        for(int i = 0 ; i < 5 ; i++) {
            for(int j = 0 ; j < 5; j++){
                newBoard[level][SIZE-1-i][SIZE-1-j] = board[n][i][j];
            }
        }
    }
    else {
        for(int i = 0 ; i < 5 ; i++) {
            for(int j = 0 ; j < 5; j++){
                newBoard[level][SIZE-1-j][i] = board[n][i][j];
            }
        }
    }
}

void backMaze(int level ) {
    if(min1 == 12) return;
    if (level == SIZE) {
        int loc_min1 = BFS();
        // local_min 이 0 이 아니고 구해진 min값보다 작을 떄 
        if(loc_min1 && loc_min1 < min1) min1 = loc_min1;
        return ; 
    }   
    for (int i = 0 ; i < SIZE ; i++ ) {
        if(!check[i]) {
            check[i] = 1;
            for(int j = 0 ; j < 4; j++) {
                turnNinty(i,level,j);
                // showBoard();
                backMaze(level + 1);
            }
            check[i] = 0;
        }
    }
    return ; 

}



int BFS(void) {
    int first = newBoard[0][0][0];
    int reach = 0;
    if(!first) return 0;
    queue <tuple <int, int, int> > q;
    q.push({0,0,0});
    distB[0][0][0]++;
    while (!q.empty()) {
        tuple <int, int, int> cur = q.front(); q.pop();
        for (int i = 0 ; i < 6 ; i++){
            int nz = Z + dz[i];
            int nx = X + dx[i];
            int ny = Y + dy[i];
            if (nx<0 || ny<0 || nz<0 || nx>=SIZE || ny>=SIZE || nz>=SIZE) continue;
            if (newBoard[nz][nx][ny] == 0 || distB[nz][nx][ny] >= 0) continue;
            q.push({nz,nx,ny});
            distB[nz][nx][ny] = distB[Z][X][Y] + 1;
            if(nz * ny * nx == 64) reach = distB[nz][nx][ny];
        }
    }
    // showDIST();
    resetDist();
    return reach;
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    resetDist();
    for (int i = 0 ; i < SIZE; i++){
        for(int j = 0 ; j < SIZE ; j++ ) {
            for(int s = 0 ; s < SIZE; s++) {
                cin >> board[i][j][s];
            }
        }
    } 
    backMaze(0);
    if(min1 == 200) cout << -1;
    else cout << min1;
    cout << '\n';

}

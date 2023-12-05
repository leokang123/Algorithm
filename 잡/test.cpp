#include <bits/stdc++.h>
#define MAX 25
using namespace std;
int dx2[5] = {0,1,0,-1,0};
int dy2[5] = {0,0,1,0,-1};
int dx[2] = {1,0};
int dy[2] = {0,1};
int dir[4] = {-1,1,1,-1};
int main(void){
    int min1 = 1000;
    int board2[MAX][MAX];
    int N,items;cin >> N >> items;
    for(int i = 0; i < N; i++){
        for(int j = 0 ; j < N;j++) cin >> board2[i][j];
    }
    
    for(int s = 0 ; s < N; s++){
        for(int j = 0; j < N ; j++){
            for(int k = 0; k < 5 ;k++){
                int dobX = s + dx2[k];
                int dobY = j + dy2[k];
                if(dobX <0 || dobY < 0 || dobX >= N || dobY >= N) continue;
                board2[dobX][dobY] *= 2;
            }
            int dir_index = 0;
            int count_index = 0;
            int count = 0;
            int step = 1;
            int curX = N/2;
            int curY = N/2;
            int item = 0;
            while(true){
                for(int i = 0; i < step;i++){
                    curY += dy[dir_index]*dir[count_index];
                    curX += dx[dir_index]*dir[count_index];
                    if(curX<0||curY<0||curX>=N||curY>=N) continue;

                    if(min1 < count) {
                        count = -1;
                        break;
                    }
                    item += board2[curX][curY];
                    count++;
                    if(item >= items){
                        if(min1 > count) min1 = count;
                        count = -1;
                        break;
                    }
                    if(count >= N* N-1){
                        count = -1;
                        break;
                    }
                }
                if(count == -1) break;
                count_index++;
                if(count_index == 4) count_index = 0;
                if(dir_index == 0) dir_index = 1;
                else if(dir_index == 1){
                    dir_index = 0;
                    step++;
                }
            }
            for(int k = 0; k < 5 ;k++){
                int dobX = s + dx2[k];
                int dobY = j + dy2[k];
                if(dobX <0 || dobY < 0 || dobX >= N || dobY >= N) continue;
                board2[dobX][dobY] /= 2;
            }
        }

    }
    if(min1 != 1000)cout << min1<<'\n';
    else cout << "HUNGRY"<<'\n';
}   
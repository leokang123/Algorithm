#include <bits/stdc++.h>
using namespace std;
string arr[5];
int check[5][5];
int dx[3] = {1, 0, -1};
int dy[3] = {0, 1, 0};
int tot_num;
int s_num;
int maxNum;
void clean(void) {
    for(int i = 0 ; i < 5 ; i++) fill(check[i], check[i] + 5, 0);

}
void checkb(void){
    for(int i = 0 ; i < 5 ; i++){
        for(int j = 0 ; j < 5 ; j++){
            cout << check[i][j] << ' ';
        }
        cout <<'\n';
    }
}

void func(int x, int y) {
    
    tot_num++;
    if(arr[y][x] == 'S') s_num++;
    check[y][x] = 1;
    // cout <<'\n' << tot_num << '\n';
    // checkb();
    if(tot_num == 7){
        if(s_num >=4) {
            maxNum++;
        }
        cout <<'\n' << tot_num << '\n';
        checkb();
        tot_num--;
        return;
    }
    for(int dir = 0 ; dir < 3 ; dir++){
        int nx = x + dx[dir];
        int ny = y + dy[dir];
        if(nx < 0 || ny < 0 || nx >= 5 || ny >= 5) continue;
        if(check[ny][nx] != 0) continue;
        func(nx, ny);
    }
    check[y][x] = 0;
    tot_num--;
    if(arr[y][x] == 'S') s_num--;
    return;
}

int main(void){
    for(int i = 0 ; i < 5 ; i++) cin >> arr[i];
    for(int i = 0 ; i < 5 ; i++) {
        for (int j = 0 ; j < 5 ; j++){
            clean();
            if(arr[i][j] == 'S') s_num++;
            func(j,i);
            if(arr[i][j] == 'S') s_num--;
        }
    }
    cout << maxNum<<'\n';
    
}
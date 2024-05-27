/* 
백트래킹에 있어서 중복해서 탐색하는지, 중복을 허용하지 않는지 등 
정확한 보드 설정이 되어있어야 우리가 원하는 결과를 얻을 수 있다 
명확하게 보드를 어떻게 정해야할지 모를땐 경우의 수가 적다 싶으면 하드 코딩을 시켜서 직접 대입하는것도
방법이라고 생각한다 
쉬운 문젠데 for문만을 통해서 경기하는 팀을 정하려다 보니까 좀 많이 꼬인 느낌이 든다 
*/

#include <bits/stdc++.h>
using namespace std;

int arr[4];
int board[6][3];
int board2[6][3];
vector<pair<int, int>> v;

void makeTeam() {
    for(int i = 0 ; i < 6; i++) {
        for(int j = i + 1 ; j < 6; j++) v.push_back({i,j});
    }
}
void win(int a, int b, int back) {
    if(back) {
        board2[a][0] -= 1;
        board2[b][2] -= 1;
        return;
    }
    board2[a][0] += 1;
    board2[b][2] += 1;
}
void draw(int a, int b, int back) {
    if(back) {
        board2[a][1] -= 1;
        board2[b][1] -= 1;
        return;
    }
    board2[a][1] += 1;
    board2[b][1] += 1;
}
void lose(int a, int b, int back) {
    if(back) {
        board2[a][2] -= 1;
        board2[b][0] -= 1;
        return;
    }
    board2[a][2] += 1;
    board2[b][0] += 1;
}


int compGame(int lev) {
    for(int j = 0 ; j < 6 ; j++) {
        for(int s = 0 ; s < 3 ; s++) {
            if(board[j][s] != board2[j][s]) return 1;
        }
    }
    arr[lev] = 1;
    return 0;
}
int game(int k, int lev) {
    if(arr[lev]) return 0;
    if (k == 15) {
        if(!arr[lev]) compGame(lev);
        return 0;
    }
    auto [home, away] = v[k];
    win(home, away, 0);
    game(k+1, lev);
    win(home, away, 1);

    draw(home, away, 0);
    game(k+1, lev);
    draw(home, away, 1);

    lose(home, away, 0);
    game(k+1, lev);
    lose(home, away, 1);

    return 0;
}
int main(void) {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    makeTeam();
    for(int i = 0 ; i < 4 ; i++) {
        for(int j = 0 ; j < 6 ; j++) {
            for(int s = 0 ; s < 3 ; s++) {
                cin >> board[j][s];
                board2[j][s] = 0;
            }
        }
        game(0, i); 
    }
    for(int i = 0 ; i < 4 ; i++) cout << arr[i] << ' ';
    return 0;
}   
#include <bits/stdc++.h>
using namespace std;
#define MAX 25
pair<int,int> arr[7];
bool isused[MAX];
string board[5];
int check[2][5][5];
int maxNum;
int sNum;
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

bool BFS(){
    queue<pair<int, int>> Q;
    int cnt = 1;
    int sCnt = 0;

    if (board[arr[0].first][arr[0].second] == 'S') sCnt++;
    Q.push(arr[0]);
    check[1][arr[0].first][arr[0].second] = 1;

    while(!Q.empty()){
        pair<int ,int> cur = Q.front(); Q.pop();
        for (int i = 0 ; i < 4 ; i++){
            int nx = cur.first + dx[i];
            int ny = cur.second + dy[i];
            if(nx < 0 || ny < 0 || nx >= 5 || ny >= 5) continue;
            if(check[0][nx][ny] != 1 || check[1][nx][ny] != 0) continue;
            check[1][nx][ny] = 1;
            Q.push({nx,ny});
            if (board[nx][ny] == 'S') sCnt++;
            cnt++;
        }
    }
    for(int i = 0 ; i < 5 ; i++) fill(check[1][0], check[1][i] + 5, 0);
    if (cnt == 7){
        if (sCnt >= 4) {
            return true;
        }
    }
    return false;
}
// 조합을 구하는 경우 1
void func1(int index, int k){
    if(k == 7){
        if(BFS()) maxNum++;
        return;
    }
    for(int i = index ; i < 25 ; i++ ){
        if(isused[i] == 1) continue;
        arr[k] = {i/5,i%5};
        isused[i] = 1;
        check[0][i/5][i%5] = 1;
        func1(i, k+1);
        check[0][i/5][i%5] = 0;
        isused[i] = 0;
    }
}

// 조합을 구하는 경우 2
void func2(int k){
    if(k == 7){
        if(BFS()) maxNum++;
        return;
    }
    for(int i = 0; i < 5 ; i++){
        for(int j = 0 ; j < 5 ; j++){
            if(check[0][i][j] == 1) continue;
            // 백트래킹에 조건식 하나만 추가되는식으로 노드들에 차등을 준다 
            if(k != 0 && arr[k-1].first * 5 + arr[k-1].second > i * 5 + j) continue; 
            arr[k] = {i,j};
            check[0][i][j] = 1;
            func2(k+1);
            check[0][i][j] = 0;
        }
    }
}

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    for (int i = 0 ; i < 5 ; i++) cin >> board[i];
    // func2(0);
    func1(0,0);
    cout << maxNum << '\n';
    return 0;
}
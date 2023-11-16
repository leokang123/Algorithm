#include <bits/stdc++.h>
using namespace std;
#define X get<0> (cur)
#define Y get<1> (cur)
#define CON get<2> (cur)
#define MAX 101
int board[MAX][MAX];
int continent[MAX][MAX];
int vis[MAX][MAX];
int conNum[100000];
int dist[MAX][MAX]; // 일단 만들어놔바 
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};
int continum = 1;
int main(void){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int num;cin >> num;
    queue<tuple<int,int,int>> Q;
    queue<tuple<int,int,int>> Q2;
    for(int i = 0;i <num; i++){
        for(int j = 0;j <num;j++){
            cin>> board[i][j];
        }
    }
    for(int i = 0 ; i < num ; i++) fill(dist[i],dist[i]+num,-1);
    for(int i = 0;i <num; i++){
        for(int j = 0;j <num;j++){
            if(board[i][j] == 0) continue;
            if(vis[i][j] == 1) continue;
            vis[i][j] = 1;
            continent[i][j] = continum;
            Q.push({i,j,continum});
            while(!Q.empty()){
                Q2.push(Q.front()); // 대륙 정보 큐에 전부 저장
                conNum[continum]++; // 대륙 넘버에 따라 각 대륙 크기 저장 
                tuple<int,int,int> cur =Q.front();Q.pop();
                for(int dir = 0; dir < 4;dir++){
                    int nx = X + dx[dir];
                    int ny = Y + dy[dir];
                    if(nx<0||nx>=num||ny<0||ny>=num) continue;
                    if(vis[nx][ny] != 0 || board[nx][ny] != 1) continue;
                    vis[nx][ny] = 1;
                    continent[nx][ny] = continum;
                    Q.push({nx,ny,continum});
                }
            }
            continum++;
        }
    }
    int min1 = 10000;
    int end1 = 0;
    // queue<tuple<int,int,int>> Q3;
    int rand = 1;
    while(!Q2.empty()){
        end1 = 0;
        int ini_rand = rand;
        int contnum = conNum[rand++];
        for(int i = 0; i < num ; i++){
            fill(dist[i],dist[i]+num,-1);
        }
        for(int i = 0; i < contnum;i++){
            Q.push(Q2.front());Q2.pop();
        }
        while(!Q.empty()){
            tuple<int, int, int> cur = Q.front(); Q.pop();
            if(!end1){
                for(int dir = 0; dir < 4; dir++){
                    int nx = X + dx[dir];
                    int ny = Y + dy[dir];
                    if(nx<0||nx>=num||ny<0||ny>=num) continue;
                    if(dist[nx][ny] >= 0 ) continue;
                    if(continent[nx][ny] != ini_rand && vis[nx][ny] == 1){
                        min1 = min(dist[X][Y] + 1,min1);
                        dist[nx][ny] = dist[X][Y] + 1;
                        end1 = 1;
                        break;
                    }
                    if(board[nx][ny] != 1){
                        dist[nx][ny] = dist[X][Y] + 1;
                        Q.push({nx,ny,CON});
                    }
                }
            }
        }
    }
    if(min1 == 10000) cout << 0<<'\n';
    else cout << min1<<'\n';
    // for(int i = 0;i < num;i++){
    //     for(int j = 0;j < num;j++){
    //         cout << dist[i][j]<<' ';
    //     }
    //     cout <<'\n';
    // }

}
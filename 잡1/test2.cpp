#include <bits/stdc++.h>
using namespace std;
#define MAX 50000

int main(void){
    int H,W,N,M;cin >> H >> W >> N >> M;
    int ud_gap = N;
    int rl_gap = M;
    int row1 = 0;
    int col1 = 0;
    for(int i = 0 ; i < H ; i = i+ud_gap+1) col1++;
    for(int i = 0 ; i < W ; i = i+rl_gap+1) row1++;
    cout << row1 * col1 << '\n';
    return 0;
}
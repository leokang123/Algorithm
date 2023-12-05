#include <bits/stdc++.h>
// 이분 탐색으로 솔루션을 찾아야 시간초과가 안난다 
using namespace std;
#define MAX 100000
int tarx,tary;
int num = 0;
int end1 = 0;
int traverse_z(int a, int b, int n){
    if(n == 0) return 0;
    int pow = 1<<(n-1);
    if(a < pow && b < pow) return traverse_z(a,b,n-1);
    else if (a < pow && b >= pow) return pow * pow + traverse_z(a,b-pow,n-1);
    else if (a >= pow && b < pow) return pow*pow * 2 + traverse_z(a-pow,b,n-1);
    else return pow * pow * 3 + traverse_z(a-pow,b-pow,n-1);
}

// 3 1 2 
int main(void){
    int N;
    cin >> N >> tarx >> tary;
    cout << traverse_z(tarx,tary,N) << '\n';
}
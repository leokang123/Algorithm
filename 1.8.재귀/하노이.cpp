#include <bits/stdc++.h>
using namespace std;

void hanoi(int a, int b, int c, int num) {
    if(num ==0) return ;
    hanoi(a,c,b,num-1);
    cout << a << ">>" << c << '\n';
    hanoi(b,a,c,num-1);
    return ;
}

int main(void) {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n ; cin >> n;
    hanoi(1,2,3,n);
    return 0;
}
#include <bits/stdc++.h>
using namespace std;

int memo[100];


// int main(void) {

//     int N ; cin >> N;
//     memo[0] = 1;
//     for(int j = 0 ; j <= 11 ; j++) {
//         memo[j+1] += memo[j];
//         memo[j+2] += memo[j];
//         memo[j+3] += memo[j];
//     }
//     for(int i = 0 ; i < N; i++){
//         int a; cin >> a;
//         cout << memo[a] << '\n';
//     }
// }


// int Plus123(int n)
// {
//   if(n <=0 ) return 0;
//   //if(memo[n]!= 0) return memo[n];
//   if(n<=3) memo[n] = 1 + Plus123(n-3)+ Plus123(n-2) + Plus123(n-1);
//   else memo[n] =  Plus123(n-3)+ Plus123(n-2) + Plus123(n-1);
//   return memo[n];
// }

// int main(void)
// {
//   int n;
//   cin>>n;
//   while(n--){
//     int a;
//     cin>>a;
//     cout<<Plus123(a)<<'\n';
//   }
//   return 0;
// }

int main(void) {
    int N ; cin >> N ;
    memo[1] = 1;
    memo[2] = 2;
    memo[3] = 4;
    for(int i = 4; i < 11 ; i++) {
        memo[i] = memo[i-1] + memo[i-2] + memo[i-3];
    }
    while(N--){
        int a; cin >> a;
        cout << memo[a] << '\n';
    }
    return 0 ;
}
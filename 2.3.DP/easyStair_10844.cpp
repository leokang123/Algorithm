// #include <bits/stdc++.h>
// using namespace std;

// long long memo[101][10];

// int main(void) {
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);

//     int N; cin >> N;
//     memo[1][0] = 0;
//     for(int i = 1 ; i <= 9 ; i++) memo[1][i] = 1;

//     for(int i = 2 ; i <= N ; i++){
//         for(int j = 0 ; j <= 9 ; j++) {
//             if (j-1 >=0) memo[i][j] += memo[i-1][j-1];
//             if (j+1 <=9) memo[i][j] += memo[i-1][j+1];
//             memo[i][j] = memo[i][j] % 1000000000;
//         }
//     }
//     long long sum = 0;
//     for(int i = 0 ; i < 10; i++) sum+= memo[N][i];
//     sum = sum % 1000000000;
//     cout << sum << '\n';
// }
#include <bits/stdc++.h>
using namespace std;

long long memo[101][10];

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N; cin >> N;
    memo[1][0] = 0;
    memo[1][1] = 1;
    memo[1][2] = 1;
    memo[1][3] = 1;
    memo[1][4] = 1;
    memo[1][5] = 1;
    memo[1][6] = 1;
    memo[1][7] = 1;
    memo[1][8] = 1;
    memo[1][9] = 1;

    for(int i = 2 ; i <= N ; i++){
        memo[i][0] = memo[i-1][1] % 1000000000;
        memo[i][1] = (memo[i-1][0] + memo[i-1][2])% 1000000000;
        memo[i][2] = (memo[i-1][1] + memo[i-1][3])% 1000000000;
        memo[i][3] = (memo[i-1][2] + memo[i-1][4])% 1000000000;
        memo[i][4] = (memo[i-1][3] + memo[i-1][5])% 1000000000;
        memo[i][5] = (memo[i-1][4] + memo[i-1][6])% 1000000000;
        memo[i][6] = (memo[i-1][5] + memo[i-1][7])% 1000000000;
        memo[i][7] = (memo[i-1][6] + memo[i-1][8])% 1000000000;
        memo[i][8] = (memo[i-1][7] + memo[i-1][9])% 1000000000;
        memo[i][9] = memo[i-1][8]% 1000000000;
    }
    long long sum = 0;
    for(int i = 0 ; i < 10; i++) sum+= memo[N][i];
    sum = sum % 1000000000;
    cout << sum << '\n';
}
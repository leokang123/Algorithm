#include <bits/stdc++.h>
using namespace std;
#define MAX 1002
int check[MAX][MAX];
char str1[MAX], str2[MAX];

void print(int x, int y) {
    if(check[x][y] == 0) return;
    if(check[x-1][y] == check[x][y-1] && check[x-1][y-1] + 1 == check[x][y]) {
        print(x-1,y-1);
        cout << str1[x];
    }
    else (check[x-1][y] > check[x][y-1])? print(x-1,y) : print(x,y-1);
}

int main(void) {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    cin >> &str1[1] >> &str2[1];
    int str1len = strlen(str1 + 1);
    int str2len = strlen(str2 + 1);
    int max1 = 0;
    for(int i = 1 ; i <= str1len ; i++) {
        for(int j = 1 ; j <= str2len ; j++) {
            if(str1[i] == str2[j]) check[i][j] = check[i-1][j-1] + 1;
            else check[i][j] = max(check[i-1][j], check[i][j-1]);
            if(max1 < check[i][j]) {
                max1 = check[i][j];
            }
        }
    }
    int count = check[str1len][str2len];
    cout << max1 << '\n';
    print(str1len,str2len);
    cout << '\n';
}

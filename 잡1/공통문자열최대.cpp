#include <bits/stdc++.h>
using namespace std;
#define MAX 4001
int check[MAX][MAX];
char arr1[MAX], arr2[MAX];

int main (void) {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    string str1, str2; 
    int max1 = 0;
    cin >> str1;
    cin >> str2;
    for(int i = 1 ; i <= str1.length() ; i++) arr1[i] = str1[i-1];
    for(int i = 1 ; i <= str2.length() ; i++) arr2[i] = str2[i-1];

    for(int i = 1 ; i <= str1.length() ; i++) {
        for(int j = 1 ; j <= str2.length() ; j++) {
            if(arr1[i] == arr2[j]) check[i][j] = check[i-1][j-1] + 1;
            else check[i][j] = 0;
            max1 = max(max1, check[i][j]);
        }
    }

    cout << max1 << '\n';
}
#include <bits/stdc++.h>
using namespace std;

int main(void) {
    int arr[2][2] = {{1,2},{3,4}};
    int arr2[2][2];

    for(int i = 0 ; i < 2 ; i++) {
        for(int j = 0 ; j < 2 ; j++) arr2[1-j][i] = arr[i][j];
    }

    for(int i = 0 ; i < 2 ; i++) {
        for(int j = 0 ; j < 2 ; j++) {
            cout << arr2[i][j] << ' ';
        }
        cout << '\n';
    }
}
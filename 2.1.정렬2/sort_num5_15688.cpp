#include <bits/stdc++.h>
using namespace std;
#define MAX 2000002

int freq[MAX];

// Counting sort
int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N;cin >> N;
    for (int i = 0; i < N; i++) {
        int a ; 
        cin >> a;
        freq[a+1000000]++;
    }
    for(int i = 0 ; i < MAX ; i++ ){
        if (freq[i] == 0) continue;
        for(int j = 0; j < freq[i] ; j++) {
            cout << i - 1000000 << '\n';
        }
    }
    return 0;
}
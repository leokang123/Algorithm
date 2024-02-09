#include <bits/stdc++.h>
using namespace std;
#define MAX 10001
int arr[MAX];
int arr2[MAX];


int main(void) {
    set <int> s;
    int N ; cin >> N ;
    for (int i = 0 ; i < N ; i++) {
        int a; cin >> a;
        arr[a]++;
        s.insert(a);
    }
    for (int i : s){
        for(int j = 0 ; j < arr[i] ; j++) {
            cout << i << ' ' ;
        }
    }

}



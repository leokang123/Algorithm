#include <bits/stdc++.h>
using namespace std;
#define MAX 100001

long long arr[MAX];

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N; cin >> N;
    long long a = 0 ;
    int b = 0;
    int max = 0;
    int b_ind = 0;
    for(int i = 0; i < N ; i++) cin >> arr[i];
    sort(arr,arr+N);
    a = arr[0];
    for( int i = 0 ; i < N ; i++) {
        if(arr[i] != a){
            a = arr[i];
            b = 0;
        }
        b++;
        if(max < b) {
            max = b;
            b_ind = i;
        }
    }
    cout << arr[b_ind] << '\n';
}
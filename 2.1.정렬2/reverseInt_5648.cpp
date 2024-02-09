#include <bits/stdc++.h>
using namespace std;
long long arr[1000001];
int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N ; cin >> N;
    string str;
    for (int i = 0 ; i < N ; i++){
        cin >> str;
        reverse(str.begin(),str.end());
        arr[i] = stoll(str);
    }
    sort(arr,arr+N);
    for(int i = 0 ; i < N ; i++) {
        cout << arr[i] << '\n';
    }
    return 0;
}
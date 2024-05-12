#include <iostream>
using namespace std;

int main(void) {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int n; cin >> n;
    int k = n - 1;
    for(int i = 0 ; i < n ; i++) {
        for(int j = 0 ; j < n ; j++) {
            if(j < k){
                cout << ' ';
                continue;
            }
            cout << '*';
        }
        cout << '\n';
        k--;
    }
    return 0;
}
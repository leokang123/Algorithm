#include <bits/stdc++.h>
using namespace std; 

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N; cin >> N;
    int a, b;
    while (N--) {
        int totNum = 0;
        vector <int> v1;
        cin >> a >> b;
        for (int i = 0 ; i < a ; i++) {
            int num1; cin >> num1;
            v1.push_back(num1);
        }
        sort(v1.begin(), v1.end());

        for (int i = 0 ; i < b ; i++) {
            int num2; cin >> num2;
            for (int j = 0 ; j < a ; j++) {
                if(v1[j] <= num2) continue;
                totNum += a - j;
                break;
            }
        }
        cout << totNum <<'\n';
    }
    return 0;
}
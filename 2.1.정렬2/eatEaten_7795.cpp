#include <bits/stdc++.h>
using namespace std; 

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N; cin >> N;
    int a, b;
    while (N--) {
        int totNum = 0;
        vector <int> v1, v2;
        cin >> a >> b;
        for (int i = 0 ; i < a ; i++) {
            int num1; cin >> num1;
            v1.push_back(num1);
        }
        for (int i = 0 ; i < b ; i++) {
            int num2; cin >> num2;
            v2.push_back(num2);
        }
        for (int n1 : v1) {
            for (int n2 : v2) {
                if(n1 > n2) totNum++;
            }
        }
        cout << totNum <<'\n';
    }
    return 0;
}
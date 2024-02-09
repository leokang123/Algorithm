#include <bits/stdc++.h>
using namespace std; 

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N; cin >> N;
    int a, b;
    while (N--) {
        int totNum = 0;
        int arr[100001] = {0,};
        cin >> a >> b;
        int max = 0;
        for (int i = 0 ; i < a ; i++) {
            int num1; cin >> num1;
            if (max < num1) max = num1;
            arr[num1] = 1;
        }
        for (int i = 0 ; i < b ; i++) {
            int num2; cin >> num2;
            for(int i = 0 ; i <= max ; i++){
                if(arr[i] == 0 || i <= num2) continue;
                totNum++;
            }
        }
        cout << totNum <<'\n';
    }
    return 0;
}
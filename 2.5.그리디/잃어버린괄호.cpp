#include <bits/stdc++.h>
using namespace std;
int main() {
    string expression; cin >> expression;
    vector<int> plusNumbers;    // '+' 연산자 뒤의 숫자들을 저장
    vector<int> minusNumbers;   // '-' 연산자 뒤의 숫자들을 저장
    istringstream iss(expression);

    int number;
    char oper = '+'; // 첫 번째 숫자를 양수로 가정
    int ismin = 0;
    while (iss >> number) {
        if (!ismin && oper == '+') {
            plusNumbers.push_back(number);
        } 
        if (ismin || oper == '-') {
            minusNumbers.push_back(number);
        }

        iss >> oper; // 연산자 읽기
        if(oper == '-') ismin = 1;
    }

    // 결과 출력
    int res = 0;
    for (int num : plusNumbers) {
        res += num;
    }
    for (int num : minusNumbers) {
        res -= num;
    }
    
    cout << res << '\n';

    return 0;
}

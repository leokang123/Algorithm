#include <iostream>
#include <sstream>
#include <string>

using namespace std;

int main() {
    stringstream ss("Hello World ");

    // 쓰기 포인터를 끝으로 보냄
    ss.seekp(0,ios::end);
    ss << 100 << ' ' << 200;  // 데이터 쓰기
    cout << ss.str() << endl;  // 현재 스트림의 내용 출력

    // 읽기 스트림 포지션을 데이터의 시작으로 이동
    ss.seekg(0);

    string str1, str2;
    int num1, num2;
    ss >> str1 >> str2 >> num1 >> num2;  // 데이터 읽기
    cout << num1 << ' ' << num2 << ' ' << str1 << ' ' << str2 << '\n';

    return 0;
}

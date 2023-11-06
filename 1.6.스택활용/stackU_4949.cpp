
#include <iostream>
#include <stack>

using namespace std;
// 이 문제는 나중에 다시 풀어보자 
int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    stack<char> s;
    stack<char> s2;
    string str;
    while(getline(cin,str)){
        for(char ch: str)
        {
            // -> 기준에 따라 조건문을 쓸줄 알아야 한다 
            if(ch == '.'){ // 문자열이 바뀌는 기준 
                if(s.empty()) { // 로직이 올바른 기준 
                    if(s2.empty()) return 0; // 탈출 조건
                    else  cout <<"yes";
                } 
                else  cout <<"no";
                cout<<'\n';
                while( !s.empty() ) s.pop();
                while( !s2.empty() ) s2.pop();
                break;
            }
            s2.push(ch);  // '.'빼고 다 입력받는 스택 
            if(ch== '(') s.push('(');
            else if(ch==')'){
                if(!s.empty() && s.top() == '(') s.pop();
                else s.push(ch);
            }
            else if(ch== '[') s.push('[');
            else if(ch==']'){
                if(!s.empty() && s.top() == '[') s.pop();
                else s.push(ch);
            }
            
        }
    }
}
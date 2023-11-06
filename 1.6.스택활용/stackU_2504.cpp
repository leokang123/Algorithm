#include <iostream>
#include <stack>
using namespace std;

int main(void)
{
    stack <char> s1;
    stack <int> s2;
    string str;cin>>str;
    string str2 = str;
    int error = 0;
    int num = 0;
    int result = 0;
    char prev = 'n';

    for(char c : str)
    {
        if(c == '(' ||c == '[')
        {
            s1.push(c);
        }
        if(!s1.empty())
        {
            if(c == ')' && s1.top() == '(') s1.pop();
            if(c == ']' && s1.top() == '[') s1.pop();
        }
        else 
        {
            if(c==')' || c==']'){
                error = 1;
                break;
            }
        }
    }
    if(!s1.empty()|| error) cout << 0 <<'\n';
    else{  // error 가 아닌 경우에 대해 코드를 돌린다 
        for(char c : str2)
        {
            if(c=='(' || c == '[')
            {
                s2.push(c);
                prev = c;
            }
            else if(c == ')')
            {
                if(prev == '(')
                {
                    s2.pop();
                    s2.push(2);
                }else
                {
                    while(s2.top()!=(int)'(') {
                        num += s2.top();
                        // cout <<"2 "<< num << '\n';
                        s2.pop();
                    }
                    s2.pop(); // 이걸 해줘야 스택에 있던 괄호의 아스키코드값이 빠진다 
                    num = num * 2;
                    s2.push(num);
                    num = 0;
                }
                prev = ')';
            }
            else if(c == ']')
            {
                if(prev == '[')
                {
                    s2.pop();
                    s2.push(3);
                }else
                {
                    while(s2.top()!=(int)'[') {
                        num += s2.top();
                        s2.pop();
                    }
                    s2.pop();// 이걸 해줘야 스택에 있던 괄호의 아스키코드값이 빠진다 
                    num = num * 3;
                    s2.push(num);
                    num = 0 ;
                }
                prev = ']';
            }
        }
        while(!s2.empty()){
            result += s2.top();
            s2.pop();
        } 

        cout << result <<'\n';
    }
}
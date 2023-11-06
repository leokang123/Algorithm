
#include <iostream>
#include <stack>
using namespace std;

int main(void)
{
    stack<char> s1;
    stack<char> s2;
    string str; 
    int N;cin>>N;
    while(N--)
    {
        cin>>str;
        for(char c: str){
            if(!s1.empty() && c == ')')
            {
                s1.pop();
            }
            else if(c == '(')s1.push(c);
            else s2.push(c);
        }
        if(s1.empty() && s2.empty()) cout << "YES" <<'\n';
        else cout <<"NO"<<'\n';
        while(!s1.empty()) s1.pop();
        while(!s2.empty()) s2.pop();
    }


}
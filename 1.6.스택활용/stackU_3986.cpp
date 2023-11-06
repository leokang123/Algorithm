
#include <iostream>
#include <stack>
using namespace std;

int main(void)
{
    stack<char> s1;
    stack<char> s2;
    string str; 
    int num = 0;
    int N;cin>>N;
    while(N--)
    {
        cin>>str;
        for(char c: str){
            if(!s1.empty() && c == s1.top())
            {
                s1.pop();
            }
            else s1.push(c);
        }
        if(s1.empty()) num++;
        while(!s1.empty()) s1.pop();
    }
    cout<< num<< '\n';


}
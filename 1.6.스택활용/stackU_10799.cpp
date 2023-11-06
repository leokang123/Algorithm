
#include <iostream>
using namespace std;

int main(void)
{
    string str;cin>>str;
    int level = 0;
    int result = 0;
    char prev = 'n';
    for(char c: str)
    {
        if(c=='(') {
            level++;
            prev = '(';
        }
        else if(c == ')')
        {
            level--;
            if(prev == '(')
            {
                result += level;
            }
            else{
                result += 1;
            }
            prev = ')';
        }
    }
    cout << result <<'\n';
}
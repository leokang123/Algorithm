#include <iostream>
#include <stack>

using namespace std;

int main(void)
{
    stack<int> s;
    int N;cin>> N;
    int i =1;
    string result = "";
    while(N--)
    {
        int num;cin>>num;
        while(i<=num){
            s.push(i++);
            result += "+\n";
        }
        if(s.size() && s.top()==num){
            s.pop();
            result += "-\n";
        }
    }
    if(!s.empty()) cout <<"NO"<<'\n';
    else cout << result;
}


#include <iostream>
#include <stack>
using namespace std;

int main(void)
{
    int N;cin>>N;
    stack<int> s;
    int num = 0;
    int sum = 0;
    int size = 0;
    while(N--)
    {
        cin >> num;
        if(num == 0) s.pop(); // 문제조건에 0이 입력되면 무조건 지울 수가 있다고 보장 
        else s.push(num);
    }
    size = s.size();
    for(int i = 0;i<size;i++)
    {
        sum += s.top();
        s.pop();
    }
    cout << sum<<'\n';
}
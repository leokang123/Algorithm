#include <iostream>
#include <deque>
using namespace std;
int cal = 0;
// void show(const deque<int>& dq)
// {
//     for(int a : dq)
//     {
//         cout << a << ' ';
//     }
//     cout <<'\n';
// }
int main(void)
{
    deque<int> dq;
    int N;int M;cin>>N>>M;
    for(int i = 1;i<=N;i++)
    {
        dq.push_back(i);
    }
    while(M--)
    {
        int num;cin>>num;
        int size = dq.size();
        int i = 0;
        while(!dq.empty())
        {
            if(dq.front() == num)
            {
                cal += (i < size-i)? i : size-i;
                dq.pop_front();
                break;
            }
            else{
                dq.push_back(dq.front());
                dq.pop_front();
                i++;
            }
            // show(dq);
        }
    }
    cout <<cal<<'\n';
}
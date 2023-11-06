#include <iostream>
#include <queue>
using namespace std; 

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    queue<int> q;
    int N;cin >> N;
    int temp = 0;
    for(int i = 1;i<=N;i++) q.push(i);
    for(int i = 0;i<N-1;i++)
    {
        if(q.size() == 1) break;
        q.pop();
        temp = q.front();
        q.pop();
        q.push(temp);
    }
    cout << q.front()<<'\n';
}

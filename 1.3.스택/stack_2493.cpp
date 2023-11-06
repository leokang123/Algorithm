#include <iostream>
#include <stack>
#include <vector>
#include <map>
using namespace std;
int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N;cin>>N;
    stack<int> s1;
    stack<int> s2;
    map<int,int> m;
    vector<int> v(N);

    for(int i=1;i<=N;i++){
        int num;cin>>num;
        s1.push(num);
        m[num] = i;      
    }
    for(int i=1;i<=N;i++){
        int temp = s1.top();
        s1.pop();
        s2.push(temp);
        while(!s1.empty() && !s2.empty() && (s1.top() >= s2.top())){
            v[m[s2.top()]] = m[s1.top()];
            s2.pop();
        }
    }
    for(int i = 1;i<=N;i++)
    {
        cout <<v[i]<<'\n';
    }

/* 스택 자료구조의 핵심은 필요한 정보만 누적시키는 것이다 
(e.g) 12345678910 987654321 2345 의 높이의 탑들이 있다 가정했을때 
1~10 까지 올라가는 동안의 탑중 가장 큰 값보다 작은 탑은 의미가 없으므로 스택에 담을 필요가 없고 
10~1 까지 작아지는 동안의 탑은 결국 오른쪽에 있는 값들은 전부 의미있는 정보이기 때문에 스택 누적을 시켜야한다
그 정보들을 바탕으로 오른쪽에 있는 탑들과 비교를 해서 스택을 pop 시킨다 
*/
}

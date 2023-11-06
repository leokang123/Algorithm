#include <iostream>
#include <deque>
#include <sstream>
#include <algorithm>
using namespace std;

// substr(pos,count)
//문자열의 pos 번째 문자 부터 count 길이 만큼의 문자열을 리턴한다
int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    deque<int> dq;
    int N,M;cin>>N;
    while(N--){
        int empty = 0;
        string func;cin>>func;
        string arr;
        cin>>M;
        cin>>arr;
        arr = arr.substr(1,arr.length()-2);
        stringstream ss(arr);
        string token;
        bool rev = false;
        while(getline(ss,token,','))
        {
            int num = stoi(token);
            dq.push_back(num);
        }
        for(char c: func)
        {
            if(c == 'R')
            {
                rev = !rev;
            }
            if(c == 'D')
            {
                if(!dq.empty())
                {
                    if(rev) dq.pop_back();
                    else dq.pop_front();
                }
                else{
                    empty = 1;
                    break;
                }
            }
        }
        if(rev) reverse(dq.begin(),dq.end());
        if(empty)
        {
            cout << "error"<<'\n';
        }
        else{
            cout << '[';
            for(deque<int>::iterator iter = dq.begin();iter!=dq.end();iter++)
            {
                cout << *iter;
                if(iter+1 != dq.end())  cout <<',';
            }
            cout<<']'<<'\n';
        }
        while(!dq.empty()) dq.pop_back();
    }

}
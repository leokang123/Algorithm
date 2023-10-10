#include <iostream>
#include <stack>
using namespace std;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    stack<int> s;
    int N;cin>>N;
    while(N--){
        string str;
        cin>>str;
        int num = 0;
        // switch 문에서는 string 으로 case를 나눌수 없음 정수형만 가능 -> 먼 점핑테이블을 만든대

        if(str == "push"){
            cin>>num;
            s.push(num);
        }
        else if(str == "pop"){
            if(s.size()){
                 cout << s.top();
                 s.pop(); // pop 만 시킴 pop 시키면서 인자를 출력시키거나 하는 건 없음 
            }
            else cout<<  "-1";
        }
        else if(str == "top"){
            if(s.size()) cout << s.top();
            else cout<< "-1";
        }
        else if(str == "empty"){
            if(s.empty()) cout<<"1";
            else cout << "0";
        }
        else if(str == "size") cout<<s.size();
        cout << '\n';
    }
}
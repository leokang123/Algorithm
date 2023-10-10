#include <iostream>
#include <queue>
using namespace std;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    queue<int> s;
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
                 cout << s.front()<< '\n';
                 s.pop(); // pop 만 시킴 pop 시키면서 인자를 출력시키거나 하는 건 없음 
            }
            else cout<<  "-1"<< '\n';
        }
        else if(str == "front"){
            if(s.size()) cout << s.front()<< '\n';
            else cout<< "-1"<<'\n';
        }
        else if(str == "back"){
            if(s.size()) cout << s.back()<< '\n';
            else cout<< "-1"<< '\n';
        }
        else if(str == "empty"){
            if(s.empty()) cout<<"1"<< '\n';
            else cout << "0"<< '\n';
        }
        else if(str == "size") cout<<s.size()<< '\n';
    }

}
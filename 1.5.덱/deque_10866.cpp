#include <iostream>
#include <deque>
using namespace std;
const int MX = 100005;
int dat[2*MX+1];
int head=MX,tail=MX;

int size(){
    return tail-head;
}
void push_front(int n)
{
    dat[--head] = n;
}
void push_back(int n)
{
    dat[tail++] = n;
}
void pop_front()
{
    head++;
}
void pop_back()
{
    tail--;
}
int front()
{
    return dat[head];
}
int back()
{
    return dat[tail-1];
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
   int N;cin>>N;
    while(N--){
        string str;
        cin>>str;
        int num = 0;
        // switch 문에서는 string 으로 case를 나눌수 없음 정수형만 가능 -> 먼 점핑테이블을 만든대

        if(str == "push_front"){
            cin>>num;
            push_front(num);
        }
        else if(str == "push_back"){
            cin>>num;
            push_back(num);
        }
        else if(str == "pop_front"){
            if(size()){
                 cout << front()<< '\n';
                 pop_front(); // pop 만 시킴 pop 시키면서 인자를 출력시키거나 하는 건 없음 
            }
            else cout<<  "-1"<< '\n';
        }
        else if(str == "pop_back"){
            if(size()){
                 cout << back()<< '\n';
                 pop_back(); // pop 만 시킴 pop 시키면서 인자를 출력시키거나 하는 건 없음 
            }
            else cout<<  "-1"<< '\n';
        }
        else if(str == "front"){
            if(size()) cout << front()<< '\n';
            else cout<< "-1"<<'\n';
        }
        else if(str == "back"){
            if(size()) cout << back()<< '\n';
            else cout<< "-1"<< '\n';
        }
        else if(str == "empty"){
            if(size() == 0) cout<<"1"<< '\n';
            else cout << "0"<< '\n';
        }
        else if(str == "size") cout<<size()<< '\n';
    }

}
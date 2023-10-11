#include <iostream>
#include <queue>
using namespace std;
const int MX = 2000005;
int dat[MX];
int head = 0,tail = 0,q_size=0;

void push(int n)
{
    dat[tail++] = n;
    q_size++;
}
void pop()
{
    head++;
    q_size--;
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

        if(str == "push"){
            cin>>num;
            push(num);
        }
        else if(str == "pop"){
            if(q_size){
                 cout << front()<< '\n';
                 pop(); // pop 만 시킴 pop 시키면서 인자를 출력시키거나 하는 건 없음 
            }
            else cout<<  "-1"<< '\n';
        }
        else if(str == "front"){
            if(q_size) cout << front()<< '\n';
            else cout<< "-1"<<'\n';
        }
        else if(str == "back"){
            if(q_size) cout << back()<< '\n';
            else cout<< "-1"<< '\n';
        }
        else if(str == "empty"){
            if(q_size == 0) cout<<"1"<< '\n';
            else cout << "0"<< '\n';
        }
        else if(str == "size") cout<<q_size<< '\n';
    }

}
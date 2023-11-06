#include <iostream>
#include <deque>
using namespace std;

const int MX = 100005;
int dat[2*MX+1];
int head=MX,tail=MX;

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
void test()
{
    for(int i = 0;i<tail-head;i++)
    {
        cout << dat[head+i]<<' ';
    }
    cout<<'\n';
}
void test1()
{
    push_front(1); // 1
    push_front(5); // 5 1
    push_back(2); // 5 1 2
    push_front(7); // 7 5 1 2
    push_back(9); // 7 5 1 2 9
    test();
    cout<<"front: " <<front()<<'\n'; // 7
    cout<<"back: "<<back()<<'\n'; // 9
    pop_back();
    pop_back();
    test();
    pop_front();
    pop_front();
    test();
}

int main(void)
{   
    test1();
}
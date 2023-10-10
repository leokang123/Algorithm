#include <iostream>
using namespace std;

const int MX = 100005;
int dat[MX];
int head = 0,tail = 0;

void push(int n)
{
    dat[tail++] = n;
}
void pop()
{
    head++;
}
void front()
{
    cout<<dat[head];
}
void back()
{
    cout<<dat[tail-1];
}
void test()
{
    push(4);
    push(3);
    front();
    back();
    pop();
    front();
    back(); // 4333 
}

int main(void)
{
    test();
}
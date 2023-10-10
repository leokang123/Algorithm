#include <iostream>
using namespace std;

const int MX = 100005;
int dat[MX];
int pos = 0; // 현재 넣을 자리 

void push(int n)
{
    dat[pos++] = n;
}
void pop()
{
    pos--;
}
void top()
{
    cout<<dat[pos-1];
}
//스택 배열 사용 

void test()
{
    push(4);
    push(3);
    push(1);
    push(6);
}
int main(void)
{

}
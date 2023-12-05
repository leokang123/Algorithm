#include <bits/stdc++.h>
using namespace std; 

void func(int a, int b, int n){
    if(n == 1){
        cout << a << ' '<< b<<'\n';
        return;
    }
    func(a,6-a-b,n-1); // 6-a-b는 a,b가 아닌 다른 곳을 의미한다 a = 1, b= 2 이면 3을 의미 
    cout <<a<<' ' << b<<'\n';
    func(6-a-b,b,n-1);
}

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int num;cin >> num;
    cout << (1<<num)-1 <<'\n'; // << left shift 되어 *2 하는거랑 똑같다 
    //하노이 일반항 은 2^n-1
    func(1,3,num);
}

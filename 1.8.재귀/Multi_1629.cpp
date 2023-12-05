#include <iostream>
using namespace std; 
using ll = long long;
ll POW(ll a, ll b, ll m){
    if(b == 1) return a % m;
    ll val = POW(a,b/2,m);
    val = val * val % m;
    if(b % 2 == 0) return val;
    return val * a % m;
}
// ll multi(ll a, ll b, ll m){
//     if(b == 0) return 1;
//     if(b == 1) return a % m;
//     if(b % 2 == 0){
//         return multi(a,b/2,m) * multi(a,b/2,m) % m;
//     }else{
//         return multi(a,b/2,m) * multi(a,(b+1)/2,m) % m;
//     }
// }

int main(void){
    ll result = 1;
    int a,b,c;cin >> a >> b >> c;
    cout << POW(a,b,c)<<'\n';;
}
#include <bits/stdc++.h>
using namespace std;

bool notprime[4000002];
int prime[2000002];
int main (void) {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int n ; cin >> n;
    int k = 0;
    for(long long i = 2 ; i <= n ; i++) {
        if(!notprime[i]){
            prime[k++] = i;
            for(long long j = i*i ; j <= n ; j+= i) notprime[j] = 1;
        }
    }
    int sum = 0;
    int cnt = 0;
    int st = 0, ed = 0;
    // ed == k 일떄 ed는 이미 갈 수있는 최대치를 갔고 st를 기다리는거임 st도 할일을 마치면 ed++로 반복문 빠져나옴 
    while (ed <= k) {
        while (sum >= n) {
            if (sum == n) cnt++;
            sum -= prime[st++];
        }
        sum += prime[ed++];
    }
    cout <<  cnt << '\n';

    return 0;
}
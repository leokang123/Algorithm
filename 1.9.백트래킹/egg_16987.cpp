#include <bits/stdc++.h>
using namespace std;

#define MAX 9
pair<int, int> arr[MAX];
int N;
int eggNum;
int maxNum;


// k번째 인덱스 달걀로 깨는 순서라는뜻 
void func(int k){
    if(k == N) {
        for(int i = 0 ; i < N ; i ++ ){
            if ( arr[i].first <= 0 ) eggNum++;
        }
        if ( maxNum < eggNum ) maxNum = eggNum;
        eggNum = 0;
        return ;
    }
    // 이 변수 선언해서 조건문으로 포문 밑에서 함수 호출하는게 정말 오래걸렸음 
    int isPassed = 1;
    for(int i = 0 ; i < N ; i++) {
        if(i == k  || arr[i].first <= 0 || arr[k].first <= 0) continue;
        isPassed = 0;
        arr[i].first -= arr[k].second;
        arr[k].first -= arr[i].second;
        func(k+1);
        arr[i].first += arr[k].second;
        arr[k].first += arr[i].second;
    }
    // (정상적으로 계란 꺨수 있는 구조에서도 포문밑에서 조건문이 없으면 함수를 호출하는 구조라 오류가 났었음)
    // 깰 계란이 없어서 포문을 통과했을때를 위한 함수임 
    if(isPassed) func(k+1);
}


int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N;
    for(int i = 0 ; i < N ; i++ ) {
        int a,b; cin >> a >>  b;
       arr[i] = {a,b};
    }
    func(0);
    cout << maxNum<<'\n';
    return 0;
}
#include <bits/stdc++.h>
using namespace std;


bool compare(pair<int,int> a,pair<int,int> b){
    return a.second > b.second;
}


int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    list <pair<int,int>> l1;
    int N;
    long long num;
    cin >> N >> num;

    for (int i = 0 ; i < N ;i++) {
        long long a;cin >> a;
        auto it = find_if(l1.begin(),l1.end(),[&a](const pair<int,int> &elem){
            return elem.first == a;
        });
        if(l1.end() == it){
            l1.push_back({a,1});
        }
        else {
            it->second += 1;
        }
    }
    // 람다 함수 사용할수 있음, 그리고 list 에서는 sort할때 벡터처럼 시작값 끝값을 쓰지 않고 바로 조건 함수를 적어줌 
    l1.sort([](const pair<int,int> &a,const pair<int,int> &b){return a.second > b.second;});
    // l1.sort(compare);
    for(auto a : l1) {
        for(int i = 0 ; i < a.second ; i++){
            cout << a.first<<' ';
        }
    }
    cout << '\n';
    return 0;
}
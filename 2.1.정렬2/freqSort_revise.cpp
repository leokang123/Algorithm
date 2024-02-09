#include <bits/stdc++.h>
using namespace std;


int main(void)  {
    map<long long, pair<int,int>> m1; // 숫자,{입력된순서,빈도수} 
    int N;
    long long num;
    cin >> N >> num;
    for (int i = 1;i <= N ; i++){
        long long a ;cin >> a;
        if(m1[a].second == 0) m1[a] = {i,1};
        else m1[a].second += 1;
    }

    vector<pair<long long,pair<int,int>>> v(m1.begin(), m1.end());
    sort(v.begin(),v.end(),[](pair<long long,pair<int,int>> a, pair<long long,pair<int,int>> b){
        // 빈도수 높은거 부터 먼저 정렬 
        if(a.second.second != b.second.second) return a.second.second > b.second.second;
        // 입력된 순서대로 정렬 
        else return a.second.first < b.second.first;
    });
    for (auto a: v){
        for(int i = 0;i < a.second.second;i++){
            cout << a.first<<' ';
        }
    }
}
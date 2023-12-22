#include <bits/stdc++.h>
using namespace std;
#define MAX 100000
tuple<int,int,int> board[MAX];

struct cmp{
    bool operator()(const tuple<int,int,int>& a,const tuple<int,int,int>& b){
        return (float)get<0>(a)/get<1>(a) < (float)get<0>(b)/get<1>(b);
    }
};
priority_queue<tuple<int,int,int>,vector<tuple<int,int,int>>,cmp> PQ;

float bound(tuple<int,int,int> u){
    int totweight;
    float result;
    return 1;
}

int main(void){
    for(int i = 0 ; i < 4; i++){
        tuple<int,int,int> cur;
        int a,b,c;
        cin >> a >> b;
        cur = {a,b,0};
        PQ.push(cur);
    }
    while(!PQ.empty()){
        tuple<int,int,int> cur = PQ.top();
        cout << get<0>(cur)<<','<<get<1>(cur)<<'\n';
        PQ.pop();
    }
    return 0;
}
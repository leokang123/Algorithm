#include <bits/stdc++.h>
using namespace std;
struct cmp {
    bool operator()(pair<int,int> a, pair<int,int> b) {
        // greater 랑 같은 효과 
        return a.second > b.second;
    }
};
int main(void) {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    priority_queue<pair<int,int>, vector<pair<int,int>>, cmp> pq;
    pq.push({1,2});
    pq.push({0,2});
    pq.push({9,5});
    pq.push({3,6});
    while(!pq.empty()) {
        auto [x,y] = pq.top(); pq.pop();
        cout << x << ' '<< y << '\n';
    }

    return 0;

}
#include <bits/stdc++.h>

using namespace std;

int main(void) {
    priority_queue<pair<int, int>, vector<pair<int,int>>, less<pair<int,int>>> pq;

    pq.push({1,2});
    pq.push({2,3});
    pq.push({3,4});
    while(!pq.empty()) {
        pair<int,int> cur = pq.top(); pq.pop();
        cout << cur.first << ' '<< cur.second << '\n';
    }
    cout << (long long)4e18 << '\n';
    return 0;
}
#include <bits/stdc++.h>
using namespace std;
#define MAX 1001000

int n; 
int check[MAX];
vector<int> v;
void print() {
    cout << '\n';
    for(int a : v) cout << a << ' ';
    cout << '\n';
}
int binSearch(int k) { 
    int high = v.size() - 1;
    int low = 0;
    int mid = 0;
    while (high  > low + 1) { 
        mid = (high + low) / 2; 
        if (v[mid] == k) return mid;
        if (v[mid] >= k) high = mid;
        else if (v[mid] < k) low = mid;
    }
    //범위 탐색인경우 무조건 low는 high보다 한칸 아래에서 종료된다 따라서 조건에 따라 low나 high를 리턴하게 해줘야한다 
    if(v[low] < k) return high;
    else return low;
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    int a; cin >> a;
    v.push_back(a);
    for(int i = 0 ; i < n-1 ; i++) {
        int a; cin >> a;
        if(v.back() >= a) v[binSearch(a)] = a;
        else v.push_back(a);
        // print();
    }
    for(auto &i : v) cout << i << ' ' ; 
    cout << '\n';
    cout << v.size() << '\n';
}
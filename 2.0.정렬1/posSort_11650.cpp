#include <bits/stdc++.h>
using namespace std;
#define MAX 100001

struct point {
    int xpos;
    int ypos;
};

bool compare(const point &first, const point &second) {
    if(first.xpos != second.xpos) return first.xpos < second.xpos;
    return first.ypos < second.ypos // compare에서는 두 값이 같을 때 false를 리턴해야 좋음 
}
int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N; cin >> N ;
    point arr[MAX];
    for(int i = 0 ; i < N ; i++) {
        cin >> arr[i].xpos >> arr[i].ypos;
    }
    stable_sort(arr,arr+N,compare);
    for(int i = 0 ; i < N ; i++) {
        cout << arr[i].xpos << ' '<< arr[i].ypos << '\n';
    }
}
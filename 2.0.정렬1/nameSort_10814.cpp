#include <bits/stdc++.h>
using namespace std;
#define MAX 100001

struct person {
    int age;
    string name;
};

bool compare(const person &first, const person &second) {
    if(first.age != second.age) return first.age < second.age;
    return false; // compare에서는 두 값이 같을 때 false를 리턴해야 좋음 
}
int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N; cin >> N ;
    person arr[MAX];
    for(int i = 0 ; i < N ; i++) {
        person a;
        cin >> a.age >> a.name;
        arr[i] = a;
    }
    stable_sort(arr,arr+N,compare);
    for(int i = 0 ; i < N ; i++) {
        cout << arr[i].age << ' '<< arr[i].name << '\n';
    }
}
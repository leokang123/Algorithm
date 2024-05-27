#include <bits/stdc++.h>
using namespace std; 
#define MAX 500001

int n, m;
int check[MAX];
int mark[MAX];

int binSearch(int k) {
    int low = -1;
    int high = n;
    int * arr = check;
    while(high > low + 1) {
        int mid = (high + low) / 2;
        if (arr[mid] == k) return mid;
        if (arr[mid] > k) high = mid;
        else low = mid;
    }
    return -1;
}

int main(void) {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cin >> n >> m;
    int cnt = n;
    for(int i = 0 ; i < n ; i++) {
        cin >> check[i];
    }
    sort(check, check + n);
    for(int i = 0 ; i < m ; i++) {
        int temp ; cin >> temp;
        int a = binSearch(temp);
        if(a == -1) continue;
        mark[a] = 1;
        cnt--;
    }
    cout << cnt << '\n';
    for(int i = 0 ; i < n ; i++) {
        if(mark[i]) continue;
        cout << check[i] << ' ';
    }
}
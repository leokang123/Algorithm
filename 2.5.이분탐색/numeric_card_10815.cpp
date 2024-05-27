#include <bits/stdc++.h>
using namespace std;
#define MAX 500001

int mine[MAX];
int yours[MAX];
int n, m;

/* 닫힌구간 [0,m-1] 을 탐색하는경우 
 * 범위를 low high, 을 한후 while문을 high >= low 까지 탐색한다 -> low가 high보다 커질수 있음 (특정 경계값을 찾을때좋음)
 */
int binSearch1(int k) {
    int low = 0;
    int high = n-1;
    int *arr = mine;
    while(high >= low) {
        int mid = (low + high) / 2;
        // cout << "mid: " << mid << ' ' << "arr[mid] : " << arr[mid] << '\n';
        if(arr[mid] == k) return mid;
        if(arr[mid] > k) high = mid-1;
        else low = mid + 1;
    }
    return -1;
}
/* 반열린구간 [0,m-1) 을 탐색하는경우 
 * 범위를 low, high+1, 을 한후 while문을 high > low 까지 탐색한다 -> low와 high의 값이 같아질수 있음 (특정 경계값을 찾을때 좋음 high=low=mid라서)
 */
int binSearch2(int k) {
    int low = 0;
    int high = n;
    int *arr = mine;
    while(high > low) {
        int mid = (low + high) / 2;
        if(arr[mid] == k) return mid;
        if(arr[mid] > k) high = mid;
        else low = mid + 1;
    }
    return -1;
}

/* 열린구간 (0,m-1) 을 탐색하는경우 
 * 범위를 low-1 high+1, 을 한후 while문을 high > low + 1까지 탐색한다 -> low가 high보다 무조건 1이상 작음 (범위의 경계가 되는 지점을 찾을때 좋음)
 */
int binSearch3(int k) {
    int low = -1;
    int high = n;
    int *arr = mine;
    while(high > low + 1) {
        int mid = (low + high) / 2;
        if(arr[mid] == k) return mid;
        if(arr[mid] > k) high = mid;
        else low = mid;
    }
    return -1;
}

int main (void) {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);


    cin >> n;
    for(int i = 0 ; i < n ; i++) {
        cin >> mine[i];
    }
    sort(mine, mine + n);
    cin >> m;
    for(int i = 0 ; i < m ; i++) {
        int temp; cin >> temp;
        if (binSearch3(temp) != -1) cout << '1' << ' ';
        else cout << '0' << ' ';
    }
    cout << '\n';
    return 0;
}
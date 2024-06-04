#include <bits/stdc++.h>
using namespace std;

int arr[] = {1,2,3,3,4,5,6,6,6,6,7,8,9,10};

int upper_bound1(int k) {
    int high = 15;
    int low = -1;
    while (high > low + 1) {
        int mid = (high + low) / 2;
        if (arr[mid] > k) high = mid;
        else low = mid;
    }
    return high;
}

int lower_bound1(int k) {
    int high = 15;
    int low = -1;
    while (high > low + 1) {
        int mid = (high + low) / 2;
        if (arr[mid] >= k) high = mid;
        else low = mid;
    }
    return high;
}

int main (void) {
    int high = 15;
    int low = -1;
    int key = 6;
    while (high > low + 1) {
        int mid = (high + low) / 2;
        if (arr[mid] > 6) high = mid;
        else low = mid;
    }
    cout << lower_bound1(6) << ' ' << upper_bound1(6) << '\n';
    cout << lower_bound(arr, arr + 14, 6) - arr << ' '<< upper_bound(arr, arr + 14, 6) - arr;
    return 0;
}
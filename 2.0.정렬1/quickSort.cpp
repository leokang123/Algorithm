#include <bits/stdc++.h>
using namespace std; 
#define MAX 10000000
int arr[MAX];

void quickSort(int left, int right) {
    if(left < right) {
        int pivot = arr[left];
        int i = left+1;
        int j = right;
        while(i <= j) {
            if(arr[i] < pivot) {
                i++;
                continue;
            }
            if(arr[j] > pivot) {
                j--;
                continue;
            }
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
            i++;
            j--;
        }
        arr[left] = arr[i-1];
        arr[i-1] = pivot;
        quickSort(left, j);
        quickSort(i,right);
    }
}


int main(void) {
    int N ; cin >> N ;
    for (int i = 0 ; i < N ; i++) cin >> arr[i];
    quickSort(0,N-1);
    for(int i = 0 ; i < N ;i++) cout << arr[i] << ' ' ;

}
#include <bits/stdc++.h> 
using namespace std;
#define MAX 10000000
int arr[MAX];
int newArr[MAX];

void merge(int sPoint, int mid, int ePoint) {
    int i = sPoint;
    int j = mid + 1;
    int k = sPoint;
     while (i <= mid && j <= ePoint) {
        if(arr[i] < arr[j]) {
            newArr[k] = arr[i];
            i++;
        }
        else {
            newArr[k] = arr[j];
            j++;
        }
        k++;
    }
    if(i > mid) {
        for(int s = j ; s <= ePoint ; s++) newArr[k++] = arr[s];
    }else {
        for(int s = i ; s <= mid ; s++) newArr[k++] = arr[s];
    }
    for(int i = sPoint ; i <= ePoint ; i++ ){
        arr[i] = newArr[i];
    }
    
}


void mergeSort(int sPoint, int ePoint) {
    if(sPoint < ePoint) {
        int mid = (sPoint + ePoint) / 2;
        mergeSort(sPoint, mid);
        mergeSort(mid + 1, ePoint);
        merge(sPoint, mid, ePoint);
    }
}


int main(void) {
    int N ; cin >> N;
    for(int i = 0 ; i < N ; i++) cin >> arr[i];
    mergeSort(0,N-1);
    for(int i = 0 ; i < N ;i++) cout << arr[i] << ' ';
    return 0 ;
}
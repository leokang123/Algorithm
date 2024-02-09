#include <bits/stdc++.h>
using namespace std;
#define MAX 2000002
int arr[MAX];
int num; 
void showArr(int N);

void siftDown(int semiRoot) {
    if (semiRoot > num ) return;

    int tempt; 
    if (semiRoot * 2 == num) {  // 자식 중 하나가 이미 정렬이 된 수인 경우 
        if(arr[semiRoot * 2] > arr[semiRoot]){
            tempt = arr[semiRoot];
            arr[semiRoot] = arr[semiRoot * 2];
            arr[semiRoot * 2] = tempt;
            return siftDown(semiRoot * 2);        }
    }
    else if (arr[semiRoot * 2 + 1] >= arr[semiRoot * 2] && semiRoot * 2 + 1 <= num) {
        if(arr[semiRoot * 2 + 1] > arr[semiRoot]) {
            tempt = arr[semiRoot];
            arr[semiRoot] = arr[semiRoot * 2 + 1];
            arr[semiRoot * 2 + 1] = tempt;
            return siftDown(semiRoot * 2 + 1);
        }
    }else if (arr[semiRoot * 2 + 1] < arr[semiRoot * 2] && semiRoot * 2 <= num) {
        if(arr[semiRoot * 2] > arr[semiRoot]) {
            tempt = arr[semiRoot];
            arr[semiRoot] = arr[semiRoot * 2];
            arr[semiRoot * 2] = tempt;
            return siftDown(semiRoot * 2);
        }
    }
    return ;
}

// int makePow(int N) {
//     int num = 1;
//     for(int i = 0 ; i < N ; i++ ){
//         num = num * 2;
//     }
//     return num;
// }

void makeHeap(int N) {
    int depth = log2(N) - 1;
    for (int i = depth ; i >=0 ; i--) {
        int totInd = 1<<i;
        for(int i = totInd ; i < totInd * 2; i++){
            if(i > num) break;
            siftDown(i);
        }
    }
}

void heapSort() {
    while(num){
        int tempt = arr[1];
        arr[1] = arr[num];
        arr[num--] = tempt;
        makeHeap(num);
    }    
}
void showArr(int N) {
    for(int i = 1 ; i <= N ; i++ ) cout << arr[i] <<'\n';
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N; cin >> N ;
    num = N;
    for (int i = 1 ; i <= N ; i++) cin >> arr[i];
    makeHeap(num);
    heapSort();
    showArr(N);
}
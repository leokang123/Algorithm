#include <bits/stdc++.h>
using namespace std; 
#define MAX 1000

int arr[MAX];
int N, W, L ;
int bridge[200];
int totTime; 
int weight;
void showBridge(){
    for(int i = 0 ; i < W ; i++ ){
        cout << bridge[i] << ' ';
    }
    cout <<'\n';
}

void shiftFunc(int n) {
    weight = 0 ;
    // showBridge();
    for (int i = 0 ; i < W-1 ; i++){
        bridge[i] = bridge[i+1];
        weight += bridge[i];
    }
    if(weight + n > L) {
        bridge[W-1] = 0;
        totTime += 1;
        // showBridge();
        shiftFunc(n);
    }
    else{
        bridge[W-1] = n;
        weight += n;
        // showBridge();
        totTime += 1;
    }
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N >> W >> L;
    for(int i = 0 ; i < N ; i++) cin >> arr[i];
    int point = 0;
    int i = 0 ; 
    weight = 1;
    while(weight){
        shiftFunc(arr[i]);
        i += 1;
    }
    cout << totTime <<'\n';

}
#include <bits/stdc++.h>
using namespace std;

int N,W,L;
int arr[1000];
int bridge[100000];
int sPoint;

void showBridge(void) {
    for(int i = sPoint ; i < sPoint + W ; i++ ){
        cout << bridge[i] <<' ' ;
    }
    cout << '\n';
}

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> W >> L ;
    for ( int i = 0 ; i < N ; i++ ) cin >> arr[i];
    int a = W - 1 ;
    int weight = 0 ; 
    int totTime = 0 ;
    for (int i = 0 ; i < N ; i++) {
        if(i != 0){
            weight -= bridge[sPoint];
            sPoint++;
        }
        if(weight + arr[i] > L) {
            bridge[a++] = 0;
            totTime++;
            i--;
        }
        else {
            bridge[a++] = arr[i];
            weight += arr[i];
            totTime++;
        }
        // showBridge();
    }   
    totTime += W;
    cout << totTime << '\n';
}
#include <bits/stdc++.h>
using namespace std;

int N,W,L;
int arr[1000];

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);   
    queue <int> q;
    cin >> N >> W >> L ;
    int weight = 0 ;
    int totTime = 0 ;
    for ( int i = 0 ; i < N ; i++ ) cin >> arr[i];
    for(int i = 0 ; i < W ; i++) q.push(0);
    int i = 0 ;
    while(!q.empty()){
        int popTruck = q.front(); q.pop();
        weight -= popTruck; 
        totTime++;
        if(weight + arr[i] > L){
            q.push(0);
            continue;
        }
        weight += arr[i];
        q.push(arr[i++]);
        if(i == N) break;
    }
    totTime += W;
    cout << totTime <<'\n';
}
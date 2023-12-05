#include <bits/stdc++.h>
using namespace std;
#define MAX 9
int arr[MAX];
bool isused[MAX];
int N,M;

void func1(int k){
    if(k == M){
        for(int i = 0; i < M ; i++){
            cout << arr[i] <<' ';
        }
        cout <<'\n';
        return;
    }
    for(int i = 1; i <= N ; i++){
            arr[k] = i;
            func1(k+1);
        }
    }

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N >> M ;
    func1(0);
}
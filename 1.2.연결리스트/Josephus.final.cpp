// 잘하는 사람 코드 
// 배열을 지울때마다 다 빈칸을 앞의 배열로 채운다음 진행한다
// 시간이 주는 이유는 탐색할 배열이 점점 줄어서 이고, 배열을 하나씩 값을 옮기는건 생각보다 부담이 아닌듯하다 
#include <iostream>
using namespace std;
int main(void){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int P[5001];
    int N,K; cin >> N >> K;
    if(N == 1){ cout << '<' << 1 <<'>' <<'\n'; return 0; }
    for(int i = 0 ; i < N;i++) P[i] = i + 1;
    int size = N, i = K-1;
    cout << '<'<<P[i]<<", ";
    for(int j = i;j < size-1;j++) P[j] = P[j+1];
    size--;
    while(size > 1){
        i = (i + K - 1) % size;
        cout << P[i]<<", ";
        for(int j = i;j < size-1;j++) P[j] = P[j+1];
        size--;
    }
    cout << P[0]<<'>'<<'\n';
}
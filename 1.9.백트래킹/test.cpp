#include <iostream>
#include <vector>

#define MAX 9 // 1부터 5까지 수의 순열을 구한다.
int N;
int M;
using namespace std;

int vis[MAX]; // 방문 여부를 저장하는 배열

void combination_DFS(int index, int count) { // count개의 수를 이용해 조합을 만듬
    if (count == M) {
        for (int i = 1; i <= N; i++) {
            if (vis[i] == 1) // 조합과 순열의 차이 (조합은 중복 제거)
                cout << i << " ";
        }
        cout << endl;
        return;
    }
    
    for (int i = index; i <= N; i++) {
        // 이미 방문한 곳이라면 건너뛴다.
        if (vis[i] == 1) continue;
            
        vis[i] = 1; // 방문 표시를 남긴다.
        combination_DFS(i, count + 1);
        vis[i] = 0; // 체크 취소 (다른 자식 노드를 체크하기 위해)
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N >> M ; 
    combination_DFS(1, 0);
    return 0;
}
    #include <bits/stdc++.h>
    using namespace std; 
    #define MAX 100001
    int N,W;
    pair<int,int> P[MAX];
    bool isProm[MAX];
    int max_val;
    void func1(int val,int W){
        if(W < 0){
            return;
        }
        if(val > max_val) max_val = val;
        for(int i = 0;i < N;i++){
            if(!isProm[i]){
                pair<int,int> cur = P[i];
                isProm[i] = 1;
                func1(val+cur.second,W-cur.first);
                isProm[i] = 0;
            }
        }
    }

    int main(void){
        cin >> N >> W;
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        pair<int, int > cur;
        int a,b;
        for(int i = 0 ; i < N ; i++){
            cin >> a >> b;
            cur = {a,b};
            P[i] = cur;
        }
        func1(0,W);
        cout << max_val<<'\n';
        return 0;
    }
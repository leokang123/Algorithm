// 내생각엔 커서의 정석 스택으로 품 
#include <bits/stdc++.h>
using namespace std;

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    stack<char> B;
    stack<char> F;
    int num; cin >> num;
    while(num--){
        string str;cin>>str;
        for(char c : str){
            if(c == '>'){
                if(F.empty()) continue;
                char f_word = F.top(); F.pop();
                B.push(f_word);
                continue;
            }
            else if(c == '<'){
                if(B.empty()) continue;
                char b_word = B.top(); B.pop();
                F.push(b_word);
                continue;
            }
            else if (c == '-'){
                if(!B.empty())B.pop();
                continue;
            }
            B.push(c);
        }
        
        while(!B.empty()){
            F.push(B.top());
            B.pop();
        }
        while(!F.empty()){
            cout << F.top();
            F.pop();
        }
        cout << '\n';
    }
}
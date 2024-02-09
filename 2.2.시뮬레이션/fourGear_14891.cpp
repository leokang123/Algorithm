#include <bits/stdc++.h>
using namespace std;
int check[5];
string gear1, gear2, gear3, gear4; 


void spinDir (int mod, int gNum, string& str) {
    if(check[gNum] == 1) return;
    check[gNum] = 1;
    if(mod == -1) {
        if (gNum == 1) {
            if(gear1[2] != gear2[6]) spinDir(1, 2, gear2);
        }
        else if (gNum == 2) {
            if(gear2[2] != gear3[6]) spinDir(1, 3, gear3);
            if(gear2[6] != gear1[2]) spinDir(1, 1, gear1);
        }
        else if (gNum == 3) {
            if(gear3[2] != gear4[6]) spinDir(1, 4, gear4);
            if(gear3[6] != gear2[2]) spinDir(1, 2, gear2);
        }
        else {
            if(gear4[6] != gear3[2]) spinDir(1, 3, gear3);
        }
        str.push_back(str[0]);
        str = str.substr(1,str.size() - 1);
        return; 
    }
    if (gNum == 1) {
        if(gear1[2] != gear2[6]) spinDir(-1, 2, gear2);
    }
    else if (gNum == 2) {
        if(gear2[2] != gear3[6]) spinDir(-1, 3, gear3);
        if(gear2[6] != gear1[2]) spinDir(-1, 1, gear1);
    }
    else if (gNum == 3) {
        if(gear3[2] != gear4[6]) spinDir(-1, 4, gear4);
        if(gear3[6] != gear2[2]) spinDir(-1, 2, gear2);
    }
    else {
        if(gear4[6] != gear3[2]) spinDir(-1, 3, gear3);
    }
    string num{str[str.size()-1]};
    str.insert(0,num);
    str.pop_back();
    return;
}
int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> gear1 >> gear2 >> gear3 >> gear4 ;
    int K; cin >> K;
    int totScore = 0;
    while (K--) {
        fill(check,check+5,0);
        totScore = 0;
        int gNum, mod;
        cin >> gNum >> mod;
        if(gNum == 1)spinDir(mod, gNum, gear1);
        else if(gNum == 2) spinDir(mod, gNum, gear2);
        else if (gNum == 3) spinDir(mod, gNum, gear3);
        else spinDir(mod, gNum, gear4);
        // cout <<'\n'<< gear1<<'\n'<<gear2<<'\n'<<gear3<<'\n'<<gear4<<'\n';
        
        if(gear1[0] == '1') totScore += 1;
        if(gear2[0] == '1') totScore += 2;
        if(gear3[0] == '1') totScore += 4;
        if(gear4[0] == '1') totScore += 8;
    }
    cout << totScore << '\n';
    return 0;
}
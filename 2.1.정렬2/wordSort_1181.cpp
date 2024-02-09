#include <bits/stdc++.h>
using namespace std;

struct  cmp
{
	bool operator()(const string& p1, const string& p2) const {
		if (p1.size() != p2.size()) {
			return p1.size() < p2.size();
		}
		else {
			return p1 < p2;
		}
	}
};

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    map<string,int, cmp> m1;
    int N; cin >> N;
    for (int i = 0 ; i < N ; i++ ){
        string str; cin >> str;
        m1[str]++;
    }
    for (auto a : m1) {
        cout << a.first << '\n';
    }

}
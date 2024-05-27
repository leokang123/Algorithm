#include <bits/stdc++.h>
using namespace std;

int main (void) {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    string str = "a 123 b 234 c 12.4";
    istringstream iss(str);
    int num1, num2;
    double num3;
    char alpha1, alpha2, alpha3;

    iss >> alpha1 >> num1 >> alpha2 >> num2 >> alpha3 >> num3;
    cout << num1 << ' ' << num2 << ' ' << num3 <<'\n';
    cout << alpha3 << ' ' << alpha2 << ' '<< alpha1 << '\n';
    return 0;
}
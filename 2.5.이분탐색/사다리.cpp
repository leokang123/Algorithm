#include <bits/stdc++.h>
using namespace std;

double pythagoras(double side, double line) {
    return max(sqrt(pow(side,2) - pow(line,2)), 0.000);
}

int main (void) {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    double x, y, c; cin >> x >> y >> c;
    double high = 3000000001;
    double low = 0;
    while (high > low + 1e-4) {
        double mid = (high + low) / 2;
        double xhi = pythagoras(x, mid);
        double yhi = pythagoras(y, mid);
        if (xhi == 0.000 || yhi == 0.000) {
            high = mid;
            continue;
        }
        if (c <= (xhi * yhi) / (xhi + yhi)) low = mid;
        else high = mid;
    }
    cout << round(1000*high) / 1000 << '\n';
}
    #include <bits/stdc++.h>
    using namespace std;

    int main (void) {
        cin.tie(nullptr);
        ios::sync_with_stdio(false);

        int n, h; cin >> n >> h;
        vector<int> v1, v2, arr2(h);
        for(int i = 0 ; i < n ; i++) {
            int a; cin >> a;
            if(i % 2 == 0) v1.push_back(a);
            else v2.push_back(a);
        }

        sort(v1.begin(), v1.end());
        sort(v2.begin(), v2.end());
        int k = 1;
        for(int i = 0 ; i < v1.size(); i++ ) {
            while (k <= v1[i]) {
                arr2[k-1] += v1.size() - i;
                k++;
            }
        }
        k = h;
        for(int i = 0 ; i < v2.size(); i++) {
            while (h - v2[i] < k) {
                arr2[k-1] += v2.size() - i;
                k--;
            }
        }

        sort(arr2.begin(), arr2.end());
        int cnt = lower_bound(arr2.begin(), arr2.end(), arr2[0]+1) - arr2.begin();
        cout << arr2[0] << ' ' <<  cnt << '\n';
        return 0;
    }
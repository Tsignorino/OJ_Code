#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minSkips(vector<int>& dist, int speed, int hoursBefore) {
        if (accumulate(dist.begin(), dist.end(), 0) > speed * 1ll * hoursBefore) {
            return -1;
        }

        int n = dist.size();
        vector<int> f(n);
        int l = -1, r = n;
        while (l + 1 < r) {
            int i = l + (r - l) / 2;

            int pre = 0;
            for (int j = 0; j < n - 1; ++j) {
                int tmp = f[j + 1];
                f[j + 1] = (f[j] + dist[j] + speed - 1) / speed * speed;
                if (i) {
                    f[j + 1] = min(f[j + 1], pre + dist[j]);
                }
                pre = tmp;
            }

            if (f[n - 1] + dist[n - 1] <= speed * 1ll * hoursBefore) {
                r = i;
            } else {
                l = i;
            }
        }

        return r;
    }
};
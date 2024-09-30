#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maximumTastiness(vector<int>& price, int k) {
        sort(price.begin(), price.end());
        
        int n = price.size();
        int l = -1, r = price[n - 1];

        while (l + 1 < r) {
            int mid = l + (r - l) / 2;

            int cnt = 1, pre = price[0];
            for (int i = 0; i < n; ++i) {
                if (price[i] - pre >= mid) {
                    cnt++;
                    pre = price[i];
                }
            }

            if (cnt >= k) {
                l = mid;
            } else {
                r = mid;
            }
        }

        return l;
    }
};

int main() {
    Solution sol;

    vector<int> price {13, 5, 1, 8, 21, 2};
    int k = 3;
    cout << sol.maximumTastiness(price, k);

    return 0;
}
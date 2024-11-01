#include <bits/stdc++.h>

using namespace std;
using ll = long long;

class Solution {
public:
    int minTaps(int n, vector<int>& ranges) {
        vector<int> right(n + 1);
        for (int i = 0; i <= n; ++i) {
            int r = ranges[i];
            right[max(i - r, 0)] = max(right[max(i - r, 0)], i + r);
        }

        int ans = 0, cur = 0, nxt = 0;
        for (int i = 0; i < n; ++i) {
            nxt = max(nxt, right[i]);
            if (i == nxt) {
                return -1;
            }
            if (i == cur) {
                cur = nxt;
                ans++;
            }
        }
        return ans;
    }
};

int main() {
    Solution sol;

    return 0;
}
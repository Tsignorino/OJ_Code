#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    using ll = long long;

    int maxPossibleScore(vector<int>& start, int d) {
        int n = start.size();
        ranges::sort(start);

        auto check = [&](int x) {
            ll pre = start[0];
            for (int i = 1; i < n; ++i) {
                pre = max(pre + x, start[i] * 1ll);
                if (pre > start[i] + d) {
                    return false;
                }
            }
            return true;
        };

        int l = 0, r = 2e9; // r = start.back() + d - start.front() + 1
        while (l + 1 < r) {
            int mid = l + (r - l) / 2;

            (check(mid) ? l : r) = mid;
        }
        return l;
    }
};

int main() {
    Solution sol;

    vector<int> start {2, 6, 13, 13};
    sol.maxPossibleScore(start, 5);

    return 0;
}
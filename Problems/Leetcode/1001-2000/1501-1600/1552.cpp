#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxDistance(vector<int>& position, int m) {
        sort(position.begin(), position.end());

        int n = position.size();
        int l = 0, r = *max_element(position.begin(), position.end());

        while (l + 1 < r) {
            int mid = l + (r - l) / 2;

            //* 当前能放下 cnt 个满足最小磁力不小于 mid 的球
            int cnt = 1, pre = position[0];
            for (int i = 0; i < n; ++i) {
                if (position[i] - pre >= mid) {
                    pre = position[i];
                    cnt++;
                }
            }

            if (cnt >= m) {
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

    vector<int> nums {1, 2, 3, 4, 7};
    int m = 3;
    cout << sol.maxDistance(nums, m);

    return 0;
}
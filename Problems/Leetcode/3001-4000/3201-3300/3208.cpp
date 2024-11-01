#include <bits/stdc++.h>

using namespace std;

static constexpr int MOD = 1e9 + 7;

class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& colors, int k) {
        // 维护以 i 为右端点的交替子数组的长度
        int n = colors.size();
        int ans = 0, cnt = 0;
        for (int i = 0; i < n * 2; ++i) {
            if (i > 0 && colors[i % n] == colors[(i - 1) % n]) {
                cnt = 0;
            }
            cnt++;
            ans += i >= n && cnt >= k;
        }
        return ans;
    }
};

int main() {
    Solution sol;

    return 0;
}
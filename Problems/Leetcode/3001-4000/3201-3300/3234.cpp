#include <bits/stdc++.h>

using namespace std;

static constexpr int MOD = 1e9 + 7;

class Solution {
public:
    int numberOfSubstrings(string s) {
        int n = s.size();

        // 记录 0 的坐标
        vector<int> ids;
        for (int i = 0; i < n; ++i) {
            if (s[i] == '0') {
                ids.emplace_back(i);
            }
        }

        int cnt = n - ids.size(); // 统计 1 的个数

        ids.emplace_back(n); // 哨兵

        int ans = 0;
        int start = 0;
        for (int i = 0; i < n; ++i) { // 枚举左端点
            for (int k = start; k < ids.size() - 1; ++k) { // 枚举左端点后续的 0
                int c0 = k - start + 1;
                int c1 = ids[k] - i + 1 - c0;
                if (c0 * c0 > cnt) {
                    break;
                }
                // 去掉一部分不合法的 1
                ans += max(ids[k + 1] - ids[k] - max(c0 * c0 - c1, 0), 0);
            }
            if (s[i] == '0') {
                start++;
            } else {
                ans += ids[start] - i; // 0 之前（全为 1 的情况）
                cnt--;
            }
        }
        return ans;
    }
};

int main() {
    Solution sol;

    return 0;
}
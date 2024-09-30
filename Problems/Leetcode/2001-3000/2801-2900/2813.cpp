#include <bits/stdc++.h>

using namespace std;

static constexpr int MOD = 1e9 + 7;

class Solution {
public:
    long long findMaximumElegance(vector<vector<int>>& items, int k) {
        /*
            将 items 按照 profit 从大到小排序（后续的项目不会使前面的 totalProfit 变大）
            用栈记录需要已经出现过的种类
                · 如果后续的项目和前面某个项目的种类相同，无需考虑
                · 否则，考虑移除前面的哪一个：
                    · 如果移除的项目只出现一次，无需考虑
                    · 否则有可能使 totalProfit 变大，一定选择（不选的话，当后面的 distinctCategories 增加时，totalProfit 不会比选择当前的更大）
        */
        ranges::sort(items, [&](const vector<int>& v1, const vector<int>& v2) { return v1[0] > v2[0]; });

        int n = items.size();
        unordered_set<int> set;
        stack<int> stk; // 记录重复种类
        long long ans = 0, tot = 0;
        for (int i = 0; i < n; ++i) {
            int v = items[i][0], c = items[i][1];
            if (i < k) {
                tot += v;
                if (!set.insert(c).second) {
                    stk.emplace(v);
                }
            } else if (!stk.empty() && set.insert(c).second) {
                tot += v - stk.top();
                stk.pop();
            }

            long long s = set.size();
            ans = max(ans, tot + s * s);

            // if (s == k) {
            //     break;
            // }
        }
        return ans;
    }
};

int main() {
    Solution sol;

    return 0;
}
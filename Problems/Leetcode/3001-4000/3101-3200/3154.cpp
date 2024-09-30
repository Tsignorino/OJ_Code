#include <bits/stdc++.h>

using namespace std;
using ll = long long;

class Solution {
public:
    int waysToReachStair(int k) {
        // 需要记录的信息：当前台阶，操作二次数，是否使用操作一
        // 注意递归边界为 i > k+1
        map<tuple<int, int, bool>, int> memo;
        auto dfs = [&](auto&& self, int i, int cnt, bool flag) -> int {
            if (i > k + 1) {
                return 0;
            }

            auto [iter, ok] = memo.emplace(tuple(i, cnt, flag), 0);
            int& res = iter->second;
            if (ok == 0) {
                return res;
            }

            res = i == k;
            res += self(self, i + (1 << cnt), cnt + 1, false);
            if (i && !flag) {
                res += self(self, i - 1, cnt, true);
            }
            return res;
        };
        return dfs(dfs, 1, 0, false);
    }
};

int main() {
    Solution sol;

    return 0;
}
#include <bits/stdc++.h>

using namespace std;

static constexpr int MOD = 1e9 + 7;

class Solution {
public:
    //* 记忆化搜索
    int _minimumSubstringsInPartition(string s) {
        int n = s.size();
        vector<int> memo(n);
        auto dfs = [&](auto&& self, int i) -> int {
            if (i < 0) {
                return 0;
            }

            int& res = memo[i];
            if (res) {
                return res;
            }

            res = INT_MAX;
            vector<int> cnt(26);
            int k = 0, mx = 0;
            for (int j = i; j >= 0; --j) {
                k += cnt[s[j] - 'a']++ == 0;
                mx = max(mx, cnt[s[j] - 'a']);
                if (i - j + 1 == k * mx) {
                    res = min(res, self(self, j - 1) + 1);
                }
            }
            return res;
        };
        return dfs(dfs, n - 1);
    }

    //* 递推
public:
    int minimumSubstringsInPartition(string s) {
        int n = s.size();
        vector<int> f(n + 1, INT_MAX);
        f[0] = 0;
        for (int i = 0; i < n; ++i) {
            vector<int> cnt(26);
            int k = 0, mx = 0;
            for (int j = i; j >= 0; --j) {
                k += cnt[s[j] - 'a']++ == 0;
                mx = max(mx, cnt[s[j] - 'a']);
                if (i - j + 1 == k * mx) {
                    f[i + 1] = min(f[i + 1], f[j] + 1);
                }
            }
        }
        return f[n];
    }
};

int main() {
    Solution sol;

    return 0;
}
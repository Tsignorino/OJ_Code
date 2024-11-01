#include <bits/stdc++.h>

using namespace std;

static constexpr int MOD = 1e9 + 7;

class Solution {
public:
    int maximumLength(string s) {
        // 单一字符且至少出现三次的子串
        int n = s.size();
        vector<vector<int>> vec(26);
        int cnt = 0;
        for (int i = 0; i < n; ++i) {
            cnt++;
            if (i + 1 == n || s[i] != s[i + 1]) {
                vec[s[i] - 'a'].emplace_back(cnt);
                cnt = 0;
            }
        }

        int ans = 0;
        for (auto& v : vec) {
            if (v.empty()) {
                continue;
            }
            v.emplace_back(0);
            v.emplace_back(0);
            ranges::sort(v, greater<>());

            ans = max({ans, v[0] - 2, min(v[0] - 1, v[1]), v[2]});
        }
        return ans == 0 ? -1 : ans;
    }
};

int main() {
    Solution sol;

    return 0;
}
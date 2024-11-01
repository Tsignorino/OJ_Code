#include <bits/stdc++.h>

using namespace std;

static constexpr int MOD = 1e9 + 7;

class Solution {
    using ll = long long;

public:
    vector<long long> countKConstraintSubstrings(string s, int k, vector<vector<int>>& queries) {
        int n = s.size();
        vector<int> left(n), cnt(2); // 以 i 为右端点的合法子串，左端点最小是 left[i]
        vector<ll> pre(n + 1); // 处理 i - left[i] + 1 的前缀和
        for (int l = 0, r = 0; r < n; ++r) {
            cnt[s[r] & 1]++;
            while (cnt[0] > k && cnt[1] > k) {
                cnt[s[l++] & 1]--;
            }
            left[r] = l;
            pre[r + 1] = pre[r] + r - l + 1;
        }

        vector<ll> ans;
        for (auto& q : queries) {
            int l = q[0], r = q[1];
            int id = lower_bound(left.begin() + l, left.begin() + r + 1, l) - left.begin();
            ans.emplace_back(pre[r + 1] - pre[id] + (id - l + 1) * 1ll * (id - l) / 2);
        }
        return ans;
    }
};

int main() {
    Solution sol;

    return 0;
}
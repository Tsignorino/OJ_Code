#include <bits/stdc++.h>

using namespace std;
using ll = long long;

constexpr int mod = 1e9 + 7;

class Solution {
public:
    vector<int> platesBetweenCandles(string s, vector<vector<int>>& queries) {
        int n = s.size();
        vector<int> sum(n + 1);

        vector<int> left(n);
        for (int i = 0, p = -1; i < n; ++i) {
            sum[i + 1] = sum[i];
            if (s[i] == '|') {
                p = i;
            } else {
                sum[i + 1]++;
            }
            left[i] = p;
        }

        vector<int> right(n);
        for (int i = n - 1, p = n; i >= 0; --i) {
            if (s[i] == '|') {
                p = i;
            }
            right[i] = p;
        }

        int m = queries.size();
        vector<int> ans(m);
        for (int i = 0; i < m; ++i) {
            vector<int>& q = queries[i];
            int l = right[q[0]], r = left[q[1]];
            if (l < r) {
                ans[i] = sum[r] - sum[l];
            }
        }
        return ans;
    }
};

int main() {
    Solution sol;

    vector<vector<int>> queries {
        {2, 5},
        {5, 9}
    };
    sol.platesBetweenCandles("**|**|***|", queries);

    return 0;
}
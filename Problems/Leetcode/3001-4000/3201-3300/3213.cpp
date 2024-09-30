#include <bits/stdc++.h>

using namespace std;

using ull = unsigned long long;
static constexpr int base = 131;
static constexpr int inf = 0x3f3f3f3f;

vector<ull> p(5e4 + 10), h(5e4 + 10);

class Solution {
public:
    int minimumCost(string s, vector<string>& words, vector<int>& costs) {
        int n = s.size(), m = words.size();

        p[0] = 1, h[0] = 0;
        for (int i = 0; i < n; ++i) {
            p[i + 1] = p[i] * base;
            h[i + 1] = h[i] * base + s[i] - 'a' + 1;
        }

        unordered_map<int, unordered_map<ull, int>> ump; // len: {h: {cost}}
        for (int i = 0; i < m; ++i) {
            auto& u = ump[words[i].size()];
            ull val = 0;
            for (char ch : words[i]) {
                val = val * base + ch - 'a' + 1;
            }
            if (!u.contains(val) || u[val] > costs[i]) {
                u[val] = costs[i];
            }
        }

        vector<int> f(n + 1, inf);
        f[0] = 0;
        for (int i = 1; i <= n; ++i) {
            for (auto& [len, u] : ump) {
                if (len > i) {
                    continue;
                }

                ull val = h[i] - h[i - len] * p[len];
                if (u.contains(val)) {
                    f[i] = min(f[i], f[i - len] + u[val]);
                }
            }
        }
        return f[n] == inf ? -1 : f[n];
    }
};

int main() {
    Solution sol;

    string s = "r";
    vector<string> words = {"r", "r", "r", "r"};
    vector<int> costs = {1, 6, 3, 3};
    sol.minimumCost(s, words, costs);

    return 0;
}
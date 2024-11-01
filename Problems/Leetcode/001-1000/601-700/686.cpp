#include <bits/stdc++.h>

using namespace std;

static constexpr int MOD = 1e9 + 7;

using ull = unsigned long long;
static constexpr int N = 5e4 + 5;
static constexpr int base = 131;
vector<ull> p(N), h(N);

void build(string& s) {
    int n = s.size();
    p[0] = 1, h[0] = 0;
    for (int i = 0; i < n; ++i) {
        p[i + 1] = p[i] * base;
        h[i + 1] = h[i] * base + s[i] - 'a' + 1;
    }
}

ull get(string& s) {
    ull val = 0;
    for (char ch : s) {
        val = val * base + (ch - 'a' + 1);
    }
    return val;
}

ull get(int l, int r) {
    return h[r] - h[l] * p[r - l];
}

class Solution {
public:
    int repeatedStringMatch(string a, string b) {
        int n = a.size(), m = b.size();
        int k = (m + n - 1) / n; // 叠加次数
        string s = string((k + 1) * n, ' ');
        for (int i = 0; i < (k + 1) * n; ++i) {
            s[i] = a[i % n];
        }

        build(s);

        ull h2 = get(b);
        for (int i = 0, j = m - 1; j < s.size(); ++i, ++j) {
            if (get(i, j + 1) == h2) {
                return j < n * k ? k : k + 1;
            }
        }
        return -1;
    }
};

int main() {
    Solution sol;

    return 0;
}
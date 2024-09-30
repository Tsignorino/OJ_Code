#include <bits/stdc++.h>

using namespace std;
using ll = long long;

static constexpr int MOD = 1e9 + 7;

void solve() {
    string s;
    cin >> s;

    int n = s.size() * 2 + 1;
    string t(n, ' ');
    for (int i = 0, j = 0; i < n; ++i) {
        t[i] = i & 1 ? s[j++] : '#';
    }

    vector<int> vec(n);
    vector<int> left(n), right(n);
    for (int i = 0, c = 0, r = 0; i < n; ++i) {
        int len = r > i ? min(vec[2 * c - i], r - i) : 1;
        while (i >= len && i + len <= n && t[i - len] == t[i + len]) {
            len++;
        }
        if (i + len > r) {
            r = i + len;
            c = i;
        }
        vec[i] = len;

        // l[i] 表示以i为左端点的最长的回文串
        // r[i] 表示以i为右端点的最长的回文串
        left[i - vec[i] + 1] = max(left[i - vec[i] + 1], vec[i] - 1);
        right[i + vec[i] - 1] = max(right[i + vec[i] - 1], vec[i] - 1);
    }

    for (int i = 3; i < n; i += 2) {
        left[i] = max(left[i], left[i - 2] - 2);
    }
    for (int i = n - 3; i >= 1; i -= 2) {
        right[i] = max(right[i], right[i + 2] - 2);
    }

    int ans = 0;
    for (int i = 0; i < n; i += 2) { // 枚举 # 为分割点
        if (right[i] && left[i]) {
            ans = max(ans, left[i] + right[i]);
        }
    }
    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}
#include <bits/stdc++.h>

using namespace std;
using ll = long long;

static constexpr int MOD = 19930726;

long long quickPow(long long a, long long b, int p) {
    long long res = 1;
    a = (a % p + p) % p;
    for (; b; b >>= 1, a = a * a % p) {
        if (b & 1) {
            res = a * res % p;
        }
    }
    return res;
}

void solve() {
    int n;
    ll k;
    string s;
    cin >> n >> k >> s;

    int m = 2 * s.size() + 1;
    string t(m, ' ');
    for (int i = 0, j = 0; i < m; ++i) {
        t[i] = i & 1 ? s[j++] : '#';
    }
    vector<int> vec(m);
    for (int i = 0, c = 0, r = 0; i < m; ++i) {
        int len = r > i ? min(vec[2 * c - i], r - i) : 1;
        while (i + len <= m && i >= len && t[i - len] == t[i + len]) {
            len++;
        }
        if (i + len > r) {
            r = i + len;
            c = i;
        }
        vec[i] = len;
    }

    ll cnt = 0;
    vector<int> res;
    for (int i = 1; i < m; i += 2) {
        if (vec[i] % 2 == 0) {
            res.emplace_back(vec[i] - 1);
            cnt += (vec[i] + 1) / 2; // 以 i 为中心的子串假如能扩展为 7 长度，那么它包含了 7, 5, 3, 1 四个值
        }
    }

    if (cnt < k) {
        cout << -1 << "\n";
        return;
    }

    ranges::sort(res);

    int ans = 1;
    for (int i = res.back(); i >= 1; i -= 2) {
        ll mn = min((ll) (res.end() - ranges::lower_bound(res, i)), k);
        k -= mn;
        ans = (ans * quickPow(i, mn, MOD)) % MOD;
        if (k == 0) {
            break;
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
#include <bits/stdc++.h>

using namespace std;
using ll = long long;

static constexpr int MOD = 1e9 + 7;

ll quickPow(ll a, ll b) {
    ll res = 1;
    for (; b; b >>= 1) {
        if (b & 1) {
            res = res * a;
        }
        a = a * a;
    }
    return res;
}

ll cnt_len(int len) {
    if (len == 1) {
        return 9;
    }
    int half_len = len / 2;
    if (len % 2 == 0) {
        return 9 * quickPow(10, half_len - 1);
    }
    return 9 * quickPow(10, half_len);
}

void solve() {
    ll n;
    cin >> n;
    n--;

    ll cnt = 0;
    int len = 1;
    string num_str = "1";

    while (true) {
        ll cnt_ss = cnt_len(len);

        if (cnt + cnt_ss >= n) {
            ll remain = n - cnt;
            string pre;

            int half_len = len / 2;
            if (len % 2 == 0) {
                pre = to_string(quickPow(10, half_len - 1) + remain - 1);
            } else {
                pre = to_string(quickPow(10, half_len) + remain - 1);
            }

            string s(pre);
            if (len % 2 == 0) {
                s += string(pre.rbegin(), pre.rend());
            } else {
                s += string(pre.rbegin() + 1, pre.rend());
            }
            cout << s << "\n";
            return;
        }

        cnt += cnt_ss;
        len++;
        num_str = to_string(stoll(num_str) + 1);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}
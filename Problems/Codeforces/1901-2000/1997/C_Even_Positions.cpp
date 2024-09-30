#include <bits/stdc++.h>

using namespace std;
using ll = long long;

static constexpr int MOD = 1e9 + 7;

void solve() {
    int n;
    string s;
    cin >> n >> s;

    int sum = 0;
    for (int i = 0; i < n; ++i) {
        if (s[i] == '(') {
            sum++;
        } else if (s[i] == ')') {
            sum--;
        } else {
            if (sum > 0) {
                s[i] = ')';
                sum--;
            } else if (sum == 0) {
                s[i] = '(';
                sum++;
            }
        }
    }

    // cout << s << "\n";

    int ans = 0;
    stack<int> q;
    for (int i = 0; i < n; ++i) {
        if (s[i] == '(') {
            q.emplace(i);
        } else {
            ans += i - q.top();
            q.pop();
        }
    }
    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) {
        solve();
    }

    return 0;
}
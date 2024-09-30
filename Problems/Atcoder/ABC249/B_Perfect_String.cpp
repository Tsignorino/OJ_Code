#include <bits/stdc++.h>

using namespace std;
using ll = long long;

static constexpr int MOD = 1'000'000'007;

void solve() {
    string s;
    cin >> s;

    int ok1 = 0, ok2 = 0, ok3 = 1;
    vector<int> upper(26), lower(26);
    for (int i = 0; i < s.size(); ++i) {
        if (isupper(s[i])) {
            ok1 |= 1;
            upper[s[i] - 'A']++;
        } else {
            ok2 |= 1;
            lower[s[i] - 'a']++;
        }
    }

    for (int i = 0; i < 26; ++i) {
        if (upper[i] >= 2 || lower[i] >= 2) {
            ok3 = 0;
            break;
        }
    }

    cout << (ok1 && ok2 && ok3 ? "Yes" : "No") << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}
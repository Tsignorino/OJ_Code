#include <bits/stdc++.h>

using namespace std;
using ll = long long;

static constexpr int MOD = 1'000'000'007;

void solve() {
    int n;
    cin >> n;

    string s;
    for (int i = 0; i < n; ++i) {
        char ch;
        cin >> ch;

        if (!s.empty() && (s.back() == 'f' && ch == 'c' || s.back() == 't' && ch == 'b')) {
            s.pop_back();
        } else {
            s.push_back(ch);
        }
    }
    cout << s.size() << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}
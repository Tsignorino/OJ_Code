#include <bits/stdc++.h>

using namespace std;
using ll = long long;

static constexpr int MOD = 1'000'000'007;

void solve() {
    int n;
    cin >> n;

    string s;
    cin >> s;

    vector<int> C(26);
    int cnt = 0, pre = '0';
    for (char ch : s) {
        if (ch == pre) {
            cnt++;
        } else {
            C[pre - 'a'] = max(C[pre - 'a'], cnt);
            cnt = 1;
            pre = ch;
        }
    }
    C[pre - 'a'] = max(C[pre - 'a'], cnt);

    cout << accumulate(C.begin(), C.end(), 0) << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}
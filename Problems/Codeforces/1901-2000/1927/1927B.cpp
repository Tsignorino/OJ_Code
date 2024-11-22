#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve() {
    int n;
    cin >> n;

    vector<int> a(n);
    int cnt[26] {};

    string s(n, ' ');
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        for (int j = 0; j < 26; ++j) {
            if (cnt[j] == a[i]) {
                cnt[j]++;
                s[i] = j + 'a';
                break;
            }
        }
    }
    cout << s << "\n";
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

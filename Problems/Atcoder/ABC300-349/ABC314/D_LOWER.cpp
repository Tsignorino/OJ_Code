#include <bits/stdc++.h>

using namespace std;
using ll = long long;

static constexpr int MOD = 1'000'000'007;

void solve() {
    int n;
    cin >> n;

    string s;
    cin >> s;

    int q;
    cin >> q;

    int last = -1;
    vector<tuple<int, int, char>> vec(q);
    for (int i = 0; i < q; ++i) {
        auto& [Op, id, ch] = vec[i];
        cin >> Op >> id >> ch;
        id--;
        
        if (Op != 1) {
            last = i;
        }
    }

    for (int i = 0; i < q; ++i) {
        auto& [Op, id, ch] = vec[i];
        if (Op == 1) {
            s[id] = ch;
        }
        if (i == last) {
            if (Op == 2) {
                for (char& ch : s) {
                    ch = tolower(ch);
                }
            } else {
                for (char& ch : s) {
                    ch = toupper(ch);
                }
            }
        }
    }

    cout << s << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}
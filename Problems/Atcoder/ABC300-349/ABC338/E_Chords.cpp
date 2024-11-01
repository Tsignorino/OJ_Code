#include <bits/stdc++.h>

using namespace std;
using ll = long long;

static constexpr int MOD = 1'000'000'007;

void solve() {
    int n;
    cin >> n;

    vector<pair<int, int>> vec(n);
    for (int i = 0; i < n; ++i) {
        int s, t;
        cin >> s >> t;
        s--, t--;

        if (s > t) {
            swap(s, t);
        }
        vec[i] = {s, t};
    }

    ranges::sort(vec, {}, [&](pair<int, int> p) { return p.second - p.first; });

    set<pair<int, int>> S;
    for (auto& [a, b] : vec) {
        auto it = S.lower_bound(pair(a, 0));
        if (it != S.begin() && prev(it)->second > a) {
            cout << "Yes\n";
            return;
        }
        while (it != S.end() && it->first < b) {
            if (it->second > b) {
                cout << "Yes\n";
                return;
            }
            it = S.erase(it);
        }
        S.emplace(a, b);
    }
    cout << "No\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}
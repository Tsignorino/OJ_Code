#include <bits/stdc++.h>

using namespace std;
using ll = long long;

static constexpr int mod = 1e9 + 7;

void solve() {
    int n;
    cin >> n;

    vector<int> vec(n);
    vector<int> ids(n + 1);
    for (int i = 0; i < n; ++i) {
        int v;
        cin >> v;
        vec[i] = v;
        ids[v] = i;
    }

    vector<pair<int, int>> ans;
    for (int i = 0; i < n; ++i) {
        if (vec[i] != i + 1) {
            int& id1 = ids[vec[i]];
            int& id2 = ids[i + 1];
            swap(vec[id1], vec[id2]);
            swap(id1, id2);
            ans.emplace_back(id1 + 1, id2 + 1);
        }
    }

    cout << ans.size() << "\n";
    for (auto& [v1, v2] : ans) {
        cout << v2 << " " << v1 << "\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}

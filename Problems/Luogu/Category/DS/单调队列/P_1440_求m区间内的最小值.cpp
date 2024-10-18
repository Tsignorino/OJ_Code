#include <bits/stdc++.h>

using namespace std;
using ll = long long;

static constexpr int MOD = 1'000'000'007;

void solve() {
    int n, m;
    cin >> n >> m;

    vector<int> vec(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> vec[i];
    }

    deque<int> q;
    cout << 0 << "\n";
    for (int i = 1; i < n; ++i) {
        while (!q.empty() && vec[i] <= vec[q.back()]) {
            q.pop_back();
        }

        q.emplace_back(i);
        if (i - q.front() >= m) {
            q.pop_front();
        }

        cout << vec[q.front()] << "\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}
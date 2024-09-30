#include <bits/stdc++.h>

using namespace std;
using ll = long long;

static constexpr int MOD = 1e9 + 7;

void solve() {
    int n, w;
    cin >> n >> w;

    priority_queue<int, vector<int>> q1;
    priority_queue<int, vector<int>, greater<int>> q2;
    for (int i = 1; i <= n; ++i) {
        int v;
        cin >> v;

        q1.emplace(v);
        if (q1.size() && q2.size()) {
            while (q2.top() < q1.top()) {
                q1.emplace(q2.top());
                q2.pop();
                q2.emplace(q1.top());
                q1.pop();
            }
        }

        int k = max(1, i * w / 100);
        while (q2.size() > k) {
            q1.emplace(q2.top());
            q2.pop();
        }
        while (q2.size() < k) {
            q2.emplace(q1.top());
            q1.pop();
        }

        cout << q2.top() << " ";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}
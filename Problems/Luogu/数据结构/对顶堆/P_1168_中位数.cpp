#include <bits/stdc++.h>

using namespace std;
using ll = long long;

static constexpr int MOD = 1e9 + 7;

void solve() {
    int n;
    cin >> n;

    priority_queue<int> q1;
    priority_queue<int, vector<int>, greater<>> q2;
    int val;
    cin >> val;
    q1.emplace(val);
    cout << q1.top() << "\n";
    for (int i = 2; i <= n; ++i) {
        int val;
        cin >> val;
        if (val > q1.top()) {
            q2.emplace(val);
        } else {
            q1.emplace(val);
        }

        while (abs((int) (q1.size() - q2.size())) > 1) {
            if (q1.size() > q2.size()) {
                q2.emplace(q1.top());
                q1.pop();
            } else {
                q1.emplace(q2.top());
                q2.pop();
            }
        }

        if (i & 1) {
            cout << (q1.size() > q2.size() ? q1.top() : q2.top()) << "\n";
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}

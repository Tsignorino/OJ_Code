#include <bits/stdc++.h>

using namespace std;
using ll = long long;

static constexpr int MOD = 1'000'000'007;

void solve() {
    int n;
    cin >> n;

    vector<string> A(n);
    for (string& s : A) {
        cin >> s;
    }

    vector<int> x, y;
    for (int i = 0; i < n; ++i) {
        x.emplace_back(0);
        y.emplace_back(i);
    }
    for (int i = 1; i < n; ++i) {
        x.emplace_back(i);
        y.emplace_back(n - 1);
    }
    for (int i = n - 2; i >= 0; --i) {
        x.emplace_back(n - 1);
        y.emplace_back(i);
    }
    for (int i = n - 2; i > 0; --i) {
        x.emplace_back(i);
        y.emplace_back(0);
    }

    vector<string> B(A);
    int m = x.size();
    for (int i = 0; i < m; ++i) {
        B[x[(i + 1) % m]][y[(i + 1) % m]] = A[x[i]][y[i]];
    }

    for (string& s : B) {
        cout << s << "\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}
#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve() {
    int n;
    cin >> n;

    vector vec(n, vector<ll>(2));
    vector<ll> p(n + 1), q(n + 1);
    vector<ll> ans(n);
    for (int i = 0; i < n; ++i) {
        cin >> vec[i][0] >> vec[i][1];
        ans[i] = vec[i][0];
        p[i + 1] = p[i] + vec[i][0];
        q[i + 1] = q[i] + vec[i][1];
    }

    if (p[n] > 0 || q[n] < 0) {
        cout << "No\n";
        return;
    }

    cout << "Yes\n";
    ll sum = p[n];
    for (int i = n - 1; i >= 0; --i) {
        sum -= vec[i][0];
        if (0 - sum > vec[i][1]) {
            sum += vec[i][1];
            ans[i] = vec[i][1];
        } else {
            ans[i] = -sum;
            break;
        }
    }
    for (ll& v : ans) {
        cout << v << " ";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}
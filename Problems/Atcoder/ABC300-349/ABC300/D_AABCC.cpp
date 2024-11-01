#include <bits/stdc++.h>

using namespace std;
using ll = long long;

static constexpr int MOD = 1'000'000'007;

static const int N = 1000000;
// static const int N = 100;

vector<int> isPrime(N + 1, 1);
vector<int> p;
auto init = []() {
    isPrime[0] = isPrime[1] = 0;
    for (int i = 2; i <= N; ++i) {
        if (!isPrime[i]) {
            continue;
        }
        for (long long j = i * 1ll * i; j <= N; j += i) {
            isPrime[j] = 0;
        }
        p.emplace_back(i);
    }
    return 0;
}();

void solve() {
    ll n;
    cin >> n;

    int m = p.size();
    vector<ll> pp;
    for (int i = 0; i < m; i++) {
        pp.emplace_back(p[i] * 1ll * p[i]);
    }

    ll ans = 0;
    for (int i = 0; i < m; i++) {
        ll a = p[i];
        if (a * a * a * a * a > n) {
            break;
        }
        for (int j = i + 1; j < m; j++) {
            ll b = p[j];
            if (a * a * b * b * b > n) {
                break;
            }

            auto iter = upper_bound(pp.begin() + j + 1, pp.end(), n / a / a / b);
            ans += iter - (pp.begin() + j + 1);
        }
    }
    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}

#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    ll n, m, a;
    cin >> n >> m >> a;
    cout << (n + a - 1) / a * ((m + a - 1) / a) << "\n";

    return 0;
}

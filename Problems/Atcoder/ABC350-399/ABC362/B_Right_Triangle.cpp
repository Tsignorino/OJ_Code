#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve() {
    vector vec(3, vector<int>(2));
    for (int i = 0; i < 3; ++i) {
        cin >> vec[i][0] >> vec[i][1];
    }

    int d1 = (vec[0][0] - vec[1][0]) * (vec[0][0] - vec[1][0]) + (vec[0][1] - vec[1][1]) * (vec[0][1] - vec[1][1]);
    int d2 = (vec[1][0] - vec[2][0]) * (vec[1][0] - vec[2][0]) + (vec[1][1] - vec[2][1]) * (vec[1][1] - vec[2][1]);
    int d3 = (vec[0][0] - vec[2][0]) * (vec[0][0] - vec[2][0]) + (vec[0][1] - vec[2][1]) * (vec[0][1] - vec[2][1]);
    vector<int> d {d1, d2, d3};
    ranges::sort(d);
    if (d[0] + d[1] == d[2]) {
        cout << "Yes";
    } else {
        cout << "No";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}
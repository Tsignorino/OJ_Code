#include <bits/stdc++.h>

using namespace std;
using ll = long long;

constexpr int MOD = 1e9 + 7;

/*
    归并排序求逆序对
*/

void solve() {
    int n;
    cin >> n;
    vector<int> vec(n);
    for (int& v : vec) {
        cin >> v;
    }

    ll ans = 0;
    vector<int> c(n);
    function<void(int, int)> mergeSort = [&](int l, int r) {
        if (l == r) {
            return;
        }

        int mid = l + (r - l) / 2;
        mergeSort(l, mid);
        mergeSort(mid + 1, r);

        int i = l, j = mid + 1, k = l;
        while (i <= mid && j <= r) {
            if (vec[i] <= vec[j]) {
                c[k++] = vec[i++];
            } else {
                c[k++] = vec[j++];
                ans += mid - i + 1;
            }
        }
        while (i <= mid) {
            c[k++] = vec[i++];
        }
        while (j <= r) {
            c[k++] = vec[j++];
        }

        copy(c.begin() + l, c.begin() + r + 1, vec.begin() + l);
    };

    mergeSort(0, n - 1);
    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(20);

    solve();

    return 0;
}

#include <bits/stdc++.h>

using namespace std;
using ll = long long;

static constexpr int MOD = 1'000'000'007;

template <typename... Args>
void print(Args... args) {
    ((cout << args << ' '), ...) << endl;
}

void solve() {
    int V1, V2, V3;
    cin >> V1 >> V2 >> V3;

    int a1 = 0, b1 = 0, c1 = 0;
    for (int a2 = 0; a2 <= 7; a2++) {
        for (int b2 = 0; b2 <= 7; b2++) {
            for (int c2 = 0; c2 <= 7; c2++) {
                for (int a3 = -7; a3 <= a2 + 7; a3++) {
                    for (int b3 = -7; b3 <= b2 + 7; b3++) {
                        for (int c3 = -7; c3 <= c2 + 7; c3++) {
                            int v1 = 0, v2 = 0, v3 = 0;
                            for (int s = 1; s < 0b1000; s++) {
                                int res = 0;
                                for (int t = s; t < 8; t++) {
                                    if ((t & s) == s) {
                                        int al = -100, ar = 100, bl = -100, br = 100, cl = -100, cr = 100;
                                        if (t & 0b0001) {
                                            al = max(al, a1), ar = min(ar, a1 + 7);
                                            bl = max(bl, b1), br = min(br, b1 + 7);
                                            cl = max(cl, c1), cr = min(cr, c1 + 7);
                                        }
                                        if (t & 0b0010) {
                                            al = max(al, a2), ar = min(ar, a2 + 7);
                                            bl = max(bl, b2), br = min(br, b2 + 7);
                                            cl = max(cl, c2), cr = min(cr, c2 + 7);
                                        }
                                        if (t & 0b0100) {
                                            al = max(al, a3), ar = min(ar, a3 + 7);
                                            bl = max(bl, b3), br = min(br, b3 + 7);
                                            cl = max(cl, c3), cr = min(cr, c3 + 7);
                                        }
                                        res += (__popcount(t ^ s) % 2 ? -1 : 1) * max(0, ar - al) * max(0, br - bl) * max(0, cr - cl);
                                    }
                                }
                                if (__popcount(s) == 1) {
                                    v1 += res;
                                } else if (__popcount(s) == 2) {
                                    v2 += res;
                                } else {
                                    v3 += res;
                                }
                            }
                            if (v1 == V1 && v2 == V2 && v3 == V3) {
                                cout << "Yes\n";
                                print(a1, b1, c1, a2, b2, c2, a3, b3, c3);
                                return;
                            }
                        }
                    }
                }
            }
        }
    }
    cout << "No\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}
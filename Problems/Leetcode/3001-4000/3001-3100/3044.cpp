#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#define N 1000001
bool is_prime[N] {};

void Eratosthenes(int n) {
    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i <= n; ++i) {
        is_prime[i] = true;
    }

    for (int i = 2; i * i <= n; ++i) {
        if (is_prime[i]) {
            for (int j = i * i; j <= n; j += i) {
                is_prime[j] = false;
            }
        }
    }
}

auto init = [] {
    Eratosthenes(1000000);
    return 0;
}();

class Solution_0 {
public:
    int mostFrequentPrime(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();
        unordered_map<int, int> ump;

        function<void(int, int)> func = [&](int x, int y) -> void {
            int num = mat[x][y];
            ump[num]++;

            int px = x, py = y;
            int val = num;
            while (--x > -1) {
                val = val * 10 + mat[x][y];
                ump[val]++;
            }

            x = px, y = py;
            val = num;
            while (++x < m) {
                val = val * 10 + mat[x][y];
                ump[val]++;
            }

            x = px, y = py;
            val = num;
            while (--y > -1) {
                val = val * 10 + mat[x][y];
                ump[val]++;
            }

            x = px, y = py;
            val = num;
            while (++y < n) {
                val = val * 10 + mat[x][y];
                ump[val]++;
            }

            x = px, y = py;
            val = num;
            while (--x > -1 && --y > -1) {
                val = val * 10 + mat[x][y];
                ump[val]++;
            }

            x = px, y = py;
            val = num;
            while (--x > -1 && ++y < n) {
                val = val * 10 + mat[x][y];
                ump[val]++;
            }

            x = px, y = py;
            val = num;
            while (++x < m && --y > -1) {
                val = val * 10 + mat[x][y];
                ump[val]++;
            }

            x = px, y = py;
            val = num;
            while (++x < m && ++y < n) {
                val = val * 10 + mat[x][y];
                ump[val]++;
            }
        };

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                func(i, j);
            }
        }

        int ans = 0, preCnt = 0;
        for (const auto& [v, cnt] : ump) {
            if (v > 10 && is_prime[v] == true) {
                if (cnt > preCnt || cnt == preCnt && ans < v) {
                    ans = v;
                    preCnt = cnt;
                }
            }
        }

        return ans == 0 ? -1 : ans;
    }
};

class Solution_1 {
    static constexpr int dirs[8][2] = {
        {1,  0 },
        {1,  1 },
        {0,  1 },
        {-1, 1 },
        {-1, 0 },
        {-1, -1},
        {0,  -1},
        {1,  -1}
    };

    bool is_prime(int n) {
        for (int i = 2; i * i <= n; i++) {
            if (n % i == 0) {
                return false;
            }
        }
        return true;
    }

public:
    int mostFrequentPrime(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();
        unordered_map<int, int> cnt;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                for (auto& d : dirs) {
                    int x = i + d[0], y = j + d[1], v = mat[i][j]; // 大于 10 的判定
                    while (x >= 0 && x < m && y >= 0 && y < n) {
                        v = v * 10 + mat[x][y];

                        if (cnt.contains(v) || is_prime(v)) { // 如果 v 在 cnt 中，那么 v 一定是质数
                            cnt[v]++;
                        }
                        x += d[0];
                        y += d[1];
                    }
                }
            }
        }

        int ans = -1, max_cnt = 0;
        for (auto& [v, c] : cnt) {
            if (c > max_cnt) {
                ans = v;
                max_cnt = c;
            } else if (c == max_cnt) {
                ans = max(ans, v);
            }
        }
        return ans;
    }
};
#include <bits/stdc++.h>

#include "debug.h"

using namespace std;
using ll = long long;

static constexpr int MOD = 1'000'000'007;

namespace DP {
    class Solution {
    public:
        int beautifulSplits(vector<int>& nums) {
            int n = nums.size();
            vector f(n + 1, vector<int>(n + 1));
            for (int i = n - 2; i >= 0; --i) {
                for (int j = n - 1; j > i; --j) {
                    if (nums[i] == nums[j]) {
                        f[i][j] = f[i + 1][j + 1] + 1;
                    }
                }
            }

            int ans = 0;
            for (int i = 0; i < n; ++i) {
                for (int j = i + 1; j < n - 1; ++j) {
                    int l1 = i + 1, l2 = j - i, l3 = n - 1 - j;
                    if (l1 <= l2 && f[0][i + 1] >= l1 || l2 <= l3 && f[i + 1][j + 1] >= l2) {
                        ans++;
                    }
                }
            }
            return ans;
        }
    };
} // namespace DP

namespace Hash {
    using ull = unsigned long long;
    static constexpr int N = 5e4 + 5;
    static constexpr int base = 131;
    static constexpr int inf = 0x3f3f3f3f;
    vector<ull> p, h;
    auto init = []() {
        p.resize(N);
        h.resize(N);
        return 0;
    }();

    void build(string& s) {
        int n = s.size();
        p[0] = 1, h[0] = 0;
        for (int i = 0; i < n; ++i) {
            p[i + 1] = p[i] * base;
            h[i + 1] = h[i] * base + (s[i] - 'a' + 1);
        }
    }
    ull get(string& s) {
        ull val = 0;
        for (char ch : s) {
            val = val * base + (ch - 'a' + 1);
        }
        return val;
    }
    ull get(int l, int r) { // [l, r]
        return h[r + 1] - h[l] * p[r - l + 1];
    }
    bool IsPre(int l1, int r1, int l2, int r2) {
        int len1 = r1 - l1 + 1;
        int len2 = r2 - l2 + 1;
        if (len1 > len2) {
            return false;
        }
        return get(l1, r1) == get(l2, l2 + len1 - 1);
    }

    class Solution {
    public:
        int beautifulSplits(vector<int>& nums) {
            string s;
            for (int& v : nums) {
                s.push_back(v + '0');
            }
            build(s);

            int n = s.size();
            int ans = 0;
            for (int i = 1; i < n - 1; ++i) {
                for (int j = i + 1; j < n; ++j) {
                    if (IsPre(0, i - 1, i, j - 1) || IsPre(i, j - 1, j, n - 1)) {
                        ans++;
                    }
                }
            }
            return ans;
        }
    };
} // namespace Hash

namespace DoubleHash {
    template <typename T>
    class StringHash {
        static const int MOD1 = 1'070'777'777;
        static const int MOD2 = 1'000'000'007;
        vector<int> pow_base1, pow_base2;
        vector<int> pre_hash1, pre_hash2;

    public:
        StringHash(const T& s) {
            int n = s.size();
            pow_base1.resize(n + 1);
            pow_base2.resize(n + 1);
            pre_hash1.resize(n + 1);
            pre_hash2.resize(n + 1);

            mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
            const int BASE1 = uniform_int_distribution<>(8e8, 9e8)(rng);
            const int BASE2 = uniform_int_distribution<>(8e8, 9e8)(rng);

            pow_base1[0] = pow_base2[0] = 1;
            for (int i = 0; i < n; i++) {
                pow_base1[i + 1] = (long long) pow_base1[i] * BASE1 % MOD1;
                pow_base2[i + 1] = (long long) pow_base2[i] * BASE2 % MOD2;
                pre_hash1[i + 1] = ((long long) pre_hash1[i] * BASE1 + s[i]) % MOD1;
                pre_hash2[i + 1] = ((long long) pre_hash2[i] * BASE2 + s[i]) % MOD2;
            }
        }

        auto get(int l, int r) { // [l, r]
            long long h1 = ((pre_hash1[r + 1] - (long long) pre_hash1[l] * pow_base1[r - l + 1]) % MOD1 + MOD1) % MOD1;
            long long h2 = ((pre_hash2[r + 1] - (long long) pre_hash2[l] * pow_base2[r - l + 1]) % MOD2 + MOD2) % MOD2;
            return h1 << 32 | h2;
        }
        bool IsPre(int l1, int r1, int l2, int r2) {
            int len1 = r1 - l1 + 1;
            int len2 = r2 - l2 + 1;
            if (len1 > len2) {
                return false;
            }
            return get(l1, r1) == get(l2, l2 + len1 - 1);
        }
    };

    class Solution {
    public:
        int beautifulSplits(vector<int>& nums) {
            StringHash H(nums);

            int n = nums.size();
            int ans = 0;
            for (int i = 1; i < n - 1; ++i) {
                for (int j = i + 1; j < n; ++j) {
                    if (H.IsPre(0, i - 1, i, j - 1) || H.IsPre(i, j - 1, j, n - 1)) {
                        ans++;
                    }
                }
            }
            return ans;
        }
    };
} // namespace DoubleHash

namespace SA {
    struct suffixArray {
        int n;
        // sa —— 后缀数组（sa[i] 表示排序为 i 的后缀编号）
        // 把字符串 str 的所有后缀按字典序排序，sa[i] 表示排名为 i 的后缀的开头下标
        // rk —— 名次数组（rk[i] 表示后缀 i 的排名）
        // rk[i] 表示当前长度下，i 开始的后缀的排名。
        vector<int> sa, rk, lc;

        suffixArray(const vector<int>& s) : n(s.size()), sa(n), lc(n - 1), rk(n) {
            iota(sa.begin(), sa.end(), 0);
            // 按所有后缀的第一个字符排序
            sort(sa.begin(), sa.end(), [&](int a, int b) { return s[a] < s[b]; });
            rk[sa[0]] = 0;
            for (int i = 1; i < n; i++) {
                rk[sa[i]] = rk[sa[i - 1]] + (s[sa[i]] != s[sa[i - 1]]);
            }

            vector<int> cnt(n), tmp;
            tmp.reserve(n);
            for (int k = 1; rk[sa[n - 1]] < n - 1; k <<= 1) {
                // 首先添加长度为 k 的后缀，然后添加其余后缀的下一半
                tmp.clear();
                for (int i = 0; i < k; i++) {
                    tmp.push_back(n - k + i);
                }
                for (int i : sa) {
                    if (i >= k) {
                        tmp.push_back(i - k);
                    }
                }

                // 使用计数排序对 tmp 中的后缀进行排序。
                // 首先计数每个排名的出现次数，然后计算排名的累积计数。
                fill(cnt.begin(), cnt.end(), 0);
                for (int i = 0; i < n; i++) {
                    cnt[rk[i]]++;
                }
                for (int i = 1; i < n; i++) {
                    cnt[i] += cnt[i - 1];
                }

                // 根据计数数组 cnt 将 tmp 中的后缀按排名顺序放入 sa。
                for (int i = n - 1; i >= 0; i--) {
                    sa[--cnt[rk[tmp[i]]]] = tmp[i];
                }

                // tmp 现在存储旧的排名，重新计算排名
                swap(rk, tmp);
                rk[sa[0]] = 0;
                for (int i = 1; i < n; i++) {
                    rk[sa[i]] = rk[sa[i - 1]] + (tmp[sa[i - 1]] < tmp[sa[i]] || sa[i - 1] + k == n || tmp[sa[i - 1] + k] < tmp[sa[i] + k]);
                }
            }

            // 最长公共前缀（LCP）
            for (int i = 0, j = 0; i < n; i++) {
                if (rk[i] == 0) {
                    j = 0;
                } else {
                    j -= j > 0;
                    while (i + j < n && sa[rk[i] - 1] + j < n && s[i + j] == s[sa[rk[i] - 1] + j]) {
                        j++;
                    }
                    lc[rk[i] - 1] = j;
                }
            }
        }
    };

    class Solution {
    public:
        int beautifulSplits(vector<int>& nums) {
            int n = nums.size();
            suffixArray sa(nums);

            static constexpr int K = 21;
            vector st(K, vector<int>(n - 1));
            st[0] = sa.lc;
            for (int j = 0; j < K - 1; j++) {
                for (int i = 0; i + (2 << j) <= n - 1; i++) {
                    st[j + 1][i] = min(st[j][i], st[j][i + (1 << j)]);
                }
            }

            auto rmq = [&](int l, int r) {
                int k = __lg(r - l);
                return min(st[k][l], st[k][r - (1 << k)]);
            };

            auto lcp = [&](int i, int j) {
                if (i == j || i == n || j == n) {
                    return min(n - i, n - j);
                }
                int a = sa.rk[i];
                int b = sa.rk[j];
                if (a > b) {
                    swap(a, b);
                }
                return min({n - i, n - j, rmq(a, b)});
            };

            auto lcs = [&](int i, int j) {
                if (i == j || i == 0 || j == 0) {
                    return min(i, j);
                }
                int a = sa.rk[n + n - i];
                int b = sa.rk[n + n - j];
                if (a > b) {
                    swap(a, b);
                }
                return min({i, j, rmq(a, b)});
            };

            auto pre = [&](int l1, int r1, int l2, int r2) {
                int len1 = r1 - l1;
                int len2 = r2 - l2;
                if (len1 > len2) {
                    return false;
                }
                return lcp(l1, l2) >= len1;
            };

            int ans = 0;
            for (int l = 1; l < n; ++l) {
                for (int r = l + 1; r < n; ++r) {
                    if (pre(0, l, l, r) || pre(l, r, r, n)) {
                        ans++;
                    }
                }
            }
            return ans;
        }
    };
} // namespace SA

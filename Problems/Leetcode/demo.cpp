#include <bits/stdc++.h>

using namespace std;
using ll = long long;

class Solution {
public:
    int minExtraChar(string s, vector<string>& dictionary) {
        unordered_set<string> set {dictionary.begin(), dictionary.end()};

        int n = s.size();
        vector<int> dp(n + 1);
        for (int i = 0; i < n; ++i) {
            dp[i + 1] = dp[i] + 1; // 不选
            for (int j = 0; j <= i; ++j) {
                if (set.count(s.substr(j, i - j + 1))) {
                    dp[i + 1] = min(dp[i + 1], dp[j]);
                }
            }
        }

        return dp[n];
    }

    int minLength(string s) {
        stack<char> stk;
        for (const char& c : s) {
            bool flag = true;
            // while (!stk.empty() && (stk.top() == 'A' && c == 'B' || stk.top() == 'C' && c == 'D')) {
            //     flag = false;
            //     stk.pop();
            //     break;
            // }
            if (!stk.empty() && (stk.top() == 'A' && c == 'B' || stk.top() == 'C' && c == 'D')) {
                flag = false;
                stk.pop();
                continue;
            }
            if (flag) {
                stk.push(c);
            }
        }
        return stk.size();
    }

    int addMinimum(string word) {
        /**
         *  两个指针 plain solution
         */
        // string s("abc");
        // int p1 = 0, p2 = 0, n = word.size();
        // int ans = 0;
        // while (p1 < n) {
        //     while (word[p1] != s[p2 % 3]) {
        //         ans++;
        //         p2++;
        //     }
        //     p1++;
        //     p2++;
        // }
        // return ans + 'c' - word[n - 1]; // 加上最后一个字符需要插入的字母数

        /**
         * 直接拼接
         */
        int n = word.size();
        int res = word[0] - word[n - 1] + 2; // 处理头尾 word[0] - 'a' + 'c' - word[n-1]
        for (int i = 1; i < n; ++i) {
            // (x + y - 1 + 3) % 3  ----  +3 可以处理 x <= y 的情况
            res += (word[i] - word[i - 1] + 2) % 3;
        }
        return res;

        /**
         * 计算组数
         */
        // int n = word.size();
        // int cnt = 1;
        // for (int i = 1; i < n; ++i) {
        //     if (word[i] <= word[i - 1]) { // 一定不在同一组
        //         cnt++;
        //     }
        // }
        // return 3 * cnt - n;

        /**
         * 动态规划
         */
        // int n = word.size();
        // vector<int> dp(n + 1); // 前 i 个字符需要插入的最小字母数
        // for (int i = 1; i <= n; ++i) {
        //     dp[i] = dp[i - 1] + 2;
        //     if (i > 1 && word[i - 1] > word[i - 2]) {
        //         dp[i] = dp[i - 1] - 1;
        //     }
        // }
        // return dp[n];
    }

    string repeatLimitedString(string s, int repeatLimit) {
        int cnt[26] {};
        for (const char& c : s) {
            cnt[c - 'a']++;
        }

        string str;
        for (int i = 25; i >= 0; --i) {
            int d1 = min(cnt[i], repeatLimit);
            str += string(d1, 'a' + i);
            cnt[i] -= d1;

            // 需要寻找分割字符
            for (int j = i - 1; j >= 0 && cnt[i] > 0; --j) {
                while (cnt[i] > 0 && cnt[j] > 0) {
                    int d2 = min(cnt[i], repeatLimit);
                    cnt[i] -= d2;

                    // 添加分割字符
                    str += string(1, 'a' + j);
                    cnt[j] -= 1;

                    str += string(d2, 'a' + i);
                }
            }
        }

        return str;
    }

    // https://leetcode.cn/problems/minimum-time-to-make-array-sum-at-most-x/
    int minimumTime(vector<int>& nums1, vector<int>& nums2, int x) {
        int n = nums1.size();

        // * 每个下标至多操作一次（如果操作多次的话，只有最后一次有效，而前面的操作还会让其他数字变大）
        // 因此最多操作 n 次，可以枚举每次操作的最小元素和

        // 假定考虑第 t 秒：
        // 如果从一开始到低 t 秒都不做任何操作，元素和为 s1 + t * s2
        // * 问题转化为 “如何分配 t 次操作，使得元素和最小”，即每次减少量的最大值

        // 如果前 t 秒中不做任何操作，那么 s = s1 + s2 * t
        // 下标为 i 的数不操作，那么它现在的值为 nums1[i] + nums2[i] * t
        // 如果它在 k 秒时置 0，那么它现在的值为 nums1[i] + nums2[i] * (t - k)
        // 这个操作让元素和减少了 nums1[i] + nums2[i] * k
        // * 系数 k 就等于被操作时的时间
        // 需要进行捆绑排序，可以考虑对下标数组进行排序，避免破坏 nums1 和 nums2 的对应关系
        vector<int> id(n);
        iota(id.begin(), id.end(), 0);
        sort(id.begin(), id.end(), [&](const int i, const int j) { return nums2[i] < nums2[j]; });

        // * 问题转化为 “如何从排序后的子序列依次选择 t 个子序列中的下标，使得减少量最大”
        // 子序列中第 j 个下标为 i，它对减少量的贡献为 nums1[i] + nums2[i] * j

        // * 定义 f[i+1][j] 表示从 0 到 i-1 中，选择 j 个下标减少量的最大值
        // 可以去掉第一个维度，并倒序循环 j
        vector<int> f(n + 1);
        for (int i = 0; i < n; ++i) {
            int v1 = nums1[id[i]], v2 = nums2[id[i]];
            for (int j = i + 1; j; --j) {
                f[j] = max(f[j], f[j - 1] + v1 + v2 * j);
            }
        }

        // 第一个满足 s1 + s2 * t - f[n][t] <= x 即是答案
        int s1 = accumulate(nums1.begin(), nums1.end(), 0);
        int s2 = accumulate(nums2.begin(), nums2.end(), 0);
        for (int t = 0; t <= n; ++t) {
            if (s1 + s2 * t - f[t] <= x) {
                return t;
            }
        }
        return -1;
    }

    // https://leetcode.cn/problems/numbers-at-most-n-given-digit-set/
    int atMostNGivenDigitSet(vector<string>& digits, int n) {
        string s = to_string(n);
        int m = s.size();
        vector<int> dp(m, -1);

        function<int(int, bool, bool)> f = [&](int i, bool free, bool fix) -> int {
            if (i == m) { // 填了数字，则为 1 种合法方案
                return fix;
            }

            if (free && fix && dp[i] >= 0) {
                return dp[i];
            }

            int res = 0;
            if (!fix) { // 前面不填数字，可以跳过当前位
                res = f(i + 1, true, false);
            }

            char up = free ? '9' : s[i];
            for (const string& d : digits) { // 题目中说明 digits 中没有 0
                if (d[0] > up) {
                    break;
                }

                // 如果当前受到约束并且填入的数字达到上限，将继续受约束，否则自由
                res += f(i + 1, free || d[0] != up, true);
            }

            if (free && fix) {
                dp[i] = res;
            }

            return res;
        };

        return f(0, false, false);
    }

    // https://leetcode.cn/problems/collecting-chocolates/
    long long minCost(vector<int>& nums, int x) {
        // * 操作次数为 0 ~ n-1
        int n = nums.size();
        vector<int> f(nums);

        ll ans = accumulate(f.begin(), f.end(), 0LL); // 初始状态（操作次数为 0）
        for (int k = 1; k < n; ++k) { // 枚举操作次数
            for (int i = 0; i < n; ++i) { // 枚举巧克力
                f[i] = min(f[i], nums[(i + k) % n]);
            }
            ans = min(ans, (ll) k * x + accumulate(f.begin(), f.end(), 0LL));
        }

        return ans;

        // int n = nums.size();
        // vector<ll> sumCost(n); // sumCost[i] 操作 i 次的总成本
        // for (int i = 0; i < n; ++i) {
        //     sumCost[i] = (ll) i * x;
        // }

        // for (int i = 0; i < n; ++i) {
        //     int v = nums[i];
        //     for (int j = i; j < n + i; ++j) {
        //         v = min(v, nums[j % n]);
        //         sumCost[j - i] += v;
        //     }
        // }

        // return *min_element(sumCost.begin(), sumCost.end());
    }

    // https://leetcode.cn/problems/split-array-largest-sum/
    int splitArray(vector<int>& nums, int k) {
        /* Solution 1 */
        // 前缀和
        // int n = nums.size();
        // vector<int> preSum(n + 1);
        // for (int i = 0; i < n; ++i) {
        //     preSum[i + 1] = preSum[i] + nums[i];
        // }

        // f[i][j] 数组前 i 个数分割为 j 段能取得的最大连续子数组的和的最大值的最小值
        //  需要考虑第 j 段的具体范围
        //  f[i][j] = min( max(f[x][j-1], sub(k+1, i)) ) (x = 0, 1, ..., i-1)
        //  不能分出来空数组  ->  i >= j
        //  f[0][0] = 0
        // vector<vector<int>> f(n + 1, vector<int>(k + 1, 1e9 + 7));
        // f[0][0] = 0;
        // for (int i = 1; i <= n; ++i) {
        //     for (int j = 1; j <= min(i, k); ++j) {
        //         for (int x = 0; x < i; ++x) {
        //             f[i][j] = min(f[i][j], max(f[x][j - 1], preSum[i] - preSum[x]));
        //         }
        //     }
        // }
        // return f[n][k];

        // todo: n-1 个空位，k-1 个隔板  ->  n-1 个数位，k-1 个置位

        /* Solution 2 */
        int n = nums.size();

        // l 为 max(nums)，r 为 sum(nums)
        int l = 0, r = 0;
        for (int i = 0; i < n; ++i) {
            r += nums[i];
            if (l < nums[i]) {
                l = nums[i];
            }
        }

        function<int(vector<int>&, int, int)> check = [&](vector<int>& nums, int x, int k) {
            int sum = 0, cnt = 1;
            for (int i = 0; i < n; ++i) {
                if (sum + nums[i] > x) {
                    cnt++;
                    sum = nums[i];
                } else {
                    sum += nums[i];
                }
            }
            return cnt <= k;
        };

        while (l < r) {
            int mid = l + (r - l) / 2;
            if (check(nums, mid, k)) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }

        return l;
    }

    // https://leetcode.cn/problems/maximum-students-taking-exam/
    int maxStudents(vector<vector<char>>& seats) {
        // * dfs(i, j) 表示在第 i 排的座位状态为 j 的条件下，前 i 排的最大学生数量
        // 座位和学生可以用二进制数表示
        int m = seats.size(), n = seats[0].size();
        vector<int> status(m); // status[i] 表示第 i 排可用座位的集合
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (seats[i][j] == '.') {
                    status[i] |= 1 << j;
                }
            }
        }

        // 递归没有副作用，即入参无论计算多少次，结果都相同，可以考虑记忆化搜索
        // vector<vector<int>> memo(m, vector<int>(1 << n, -1));

        // function<int(int, int)> dfs = [&] (int i, int j) -> int {
        //     int& res = memo[i][j];
        //     if (res != -1) {
        //         return res;
        //     }

        //     if (i == 0) {
        //         if (j == 0) {
        //             return res = 0;
        //         }

        //         int lowbit = j & -j;
        //         return res = dfs(i, j & ~(lowbit * 3)) + 1;
        //     }

        //     res = dfs(i - 1, status[i - 1]);
        //     for (int s = j; s; s = (s - 1) & j) { // 枚举 j 的子集 s
        //         if ((s & (s >> 1)) == 0) {
        //             int t = status[i - 1] & ~(s << 1 | s >> 1);
        //             res = max(res, dfs(i - 1, t) + __builtin_popcount(s));
        //         }
        //     }
        //     return res;
        //     };

        // return dfs(m - 1, status[m - 1]);

        vector<vector<int>> f(m, vector<int>(1 << n));
        for (int j = 1; j < (1 << n); ++j) {
            int lowbit = j & -j;
            f[0][j] = f[0][j & ~(lowbit * 3)] + 1;
        }

        for (int i = 1; i < m; ++i) {
            for (int j = status[i]; j; j = (j - 1) & status[i]) {
                f[i][j] = f[i - 1][status[i - 1]];
                for (int s = j; s; s = (s - 1) & j) {
                    if ((s & (s >> 1)) == 0) {
                        int t = status[i - 1] & ~(s << 1 | s >> 1);
                        f[i][j] = max(f[i][j], f[i - 1][t] + f[0][s]);
                    }
                }
            }
            f[i][0] = f[i - 1][status[i - 1]];
        }

        return f[m - 1][status[m - 1]];
    }

    // https://leetcode.cn/problems/sliding-subarray-beauty/
    vector<int> getSubarrayBeauty(vector<int>& nums, int k, int x) {
        constexpr int N = 50;
        int n = nums.size();
        int cnt[N * 2 + 1] {};
        for (int i = 0; i < k - 1; ++i) { // 添加 k-1 个数
            cnt[nums[i] + N]++;
        }

        vector<int> ans(n - k + 1);
        for (int i = k - 1; i < n; ++i) {
            cnt[nums[i] + N]++;

            // * 第 x 小的数指 < num 的数有 < x 个， <= num 的数有 >= x 个
            int v = x;
            for (int j = 0; j < N; ++j) { // * 暴力枚举负数的范围
                v -= cnt[j];
                if (v <= 0) {
                    ans[i - k + 1] = j - N;
                    break;
                }
            }

            cnt[nums[i - k + 1] + N]--;
        }

        return ans;
    }

    bool checkInclusion(string s1, string s2) {
        int m = s1.size(), n = s2.size();
        if (m > n) {
            return false;
        }

        // * solution 1
        //         // vector<int> cnt1(26), cnt2(26);
        // for (int i = 0; i < m; ++i) {
        //     cnt1[s1[i] - 'a']++;
        // }

        // for (int l = 0, r = 0; r < n; ++r) {
        //     cnt2[s2[r] - 'a']++;

        //     if (r - l + 1 >= m) {
        //         if (cnt1 == cnt2) {
        //             return true;
        //         }

        //         cnt2[s2[l] - 'a']--;
        //         l++;
        //     }
        // }

        // return false;

        // * Solution 2
        // vector<int> cnt(26);
        // for (int i = 0; i < m; ++i) {
        //     cnt[s1[i] - 'a']--;
        //     cnt[s2[i] - 'a']++;
        // }

        // // 先判断第一个窗口
        // int diff = 0;
        // for (int& c : cnt) {
        //     diff += c != 0;
        // }

        // if (diff == 0) {
        //     return true;
        // }

        // for (int i = m; i < n; ++i) {
        //     int x = s2[i] - 'a', y = s2[i - m] - 'a';

        //     if (x == y) {
        //         continue;
        //     }

        //     if (cnt[x] == 0) {
        //         diff++;
        //     }
        //     cnt[x]++;
        //     if (cnt[x] == 0) {
        //         diff--;
        //     }

        //     if (cnt[y] == 0) {
        //         diff++;
        //     }
        //     cnt[y]--;
        //     if (cnt[y] == 0) {
        //         diff--;
        //     }

        //     if (diff == 0) {
        //         return true;
        //     }
        // }

        // return false;

        // * Solution 3
        vector<int> cnt(26);
        for (int i = 0; i < m; ++i) {
            cnt[s1[i] - 'a']--;
        }

        for (int l = 0, r = 0; r < n; ++r) {
            cnt[s2[r] - 'a']++;

            while (cnt[s2[r] - 'a'] > 0) {
                cnt[s2[l] - 'a']--;
                l++;
            }

            if (r - l + 1 == m) {
                return true;
            }
        }
        return false;
    }

    long long maximumSumOfHeights(vector<int>& maxHeights) {
        int n = maxHeights.size();
        long long sSum = 0;
        vector<long long> suf(n + 1);
        stack<int> stk;
        stk.push(n); // 哨兵
        for (int i = n - 1; i >= 0; --i) {
            while (stk.size() > 1 && maxHeights[i] <= maxHeights[stk.top()]) {
                int v = stk.top();
                stk.pop();
                sSum -= (long long) maxHeights[v] * (stk.top() - v);
            }
            sSum += (long long) maxHeights[i] * (stk.top() - i);
            suf[i] = sSum;

            stk.push(i);
        }

        long long ans = sSum;
        stk = stack<int>();
        stk.push(-1);
        long long pSum = 0;
        for (int i = 0; i < n; ++i) {
            while (stk.size() > 1 && maxHeights[i] <= maxHeights[stk.top()]) {
                int v = stk.top();
                stk.pop();
                pSum -= (long long) maxHeights[v] * (v - stk.top());
            }
            pSum += (long long) maxHeights[i] * (i - stk.top());
            ans = max(ans, pSum + suf[i + 1]);
            stk.push(i);
        }

        return ans;
    }
};

int main() {
    Solution sol;

    vector<int> vec {5, 3, 4, 1, 1};
    cout << sol.maximumSumOfHeights(vec);

    return 0;
}

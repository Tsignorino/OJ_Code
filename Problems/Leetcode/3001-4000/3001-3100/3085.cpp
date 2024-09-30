#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minimumDeletions(string word, int k) {
        int cnt[26] {};
        for (char& ch : word) {
            cnt[ch - 'a']++;
        }

        ranges::sort(cnt);

        int maxV = 0;
        for (int i = 0; i < 26; ++i) {
            int sum = 0;
            for (int j = i; j < 26; ++j) {
                sum += min(cnt[j], cnt[i] + k);
            }
            maxV = max(maxV, sum);
        }

        return word.size() - maxV;
    }

public:
    //* hash + sort + BF (+ binary_find) / prefix_sum + slide_window
    int my_minimumDeletions(string word, int k) {
        unordered_map<int, int> ump;
        for (char& ch : word) {
            ump[ch - 'a']++;
        }

        vector<int> vec;
        for (auto& [v, cnt] : ump) {
            vec.emplace_back(cnt);
        }

        int n = vec.size();
        ranges::sort(vec);

        //* Sol 1:
        // int ans = 1e9;
        // for (int& v1 : vec) {
        //     int res = 0;
        //     for (int& v2 : vec) {
        //         if (v2 < v1) {
        //             res += v2;
        //         }
        //         if (v2 > v1 + k) {
        //             res += v2 - v1 - k;
        //         }
        //     }
        //     ans = min(ans, res);
        // }
        //
        // return ans;

        //* Sol 2:
        // int ans = 1e9;
        // for (int i = 0; i < n; ++i) { // vec[i]
        //     int cnt = 0;

        //     int id1 = lower_bound(vec.begin(), vec.end(), vec[i]) - vec.begin() - 1;
        //     int id2 = upper_bound(vec.begin(), vec.end(), vec[i] + k) - vec.begin();
        //     for (int j = 0; j < n; ++j) {
        //         if (j <= id1) {
        //             cnt += vec[j];
        //         } else if (j >= id2) {
        //             cnt += vec[j] - vec[i] - k;
        //         }
        //     }
        //     ans = min(ans, cnt);
        // }
        //
        // return ans;

        //* Sol 3:
        vector<int> preSum(n + 1);
        for (int i = 0; i < n; ++i) {
            preSum[i + 1] = preSum[i] + vec[i];
        }

        long long ans = 1e9;
        for (int l = 0, r = 0; l < n; ++l) {
            while (r < n && vec[r] - vec[l] <= k) {
                r++;
            }

            ans = min(ans, (preSum[n] - preSum[r]) - (n - r) * 1LL * (vec[l] + k) + preSum[l]);
        }

        return ans;
    }
};

int main() {
    Solution sol;

    string s("dabdcbdcdcd");
    cout << sol.minimumDeletions(s, 2);

    return 0;
}
#include <bits/stdc++.h>

using namespace std;

static constexpr int MOD = 1e9 + 7;

class Solution {
public:
    long long numberOfPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        unordered_map<int, int> cnt;
        for (int& v : nums1) {
            if (v % k == 0) {
                cnt[v / k]++;
            }
        }
        if (cnt.empty()) {
            return 0;
        }

        unordered_map<int, int> ump;
        for (int& v : nums2) {
            ump[v]++;
        }

        long long ans = 0;
        int u = ranges::max_element(cnt)->first;
        for (auto& [i, c] : ump) {
            long long s = 0;
            for (int j = i; j <= u; j += i) {
                s += cnt.contains(j) ? cnt[j] : 0;
            }
            ans += s * c;
        }
        return ans;
    }
};

int main() {
    Solution sol;

    return 0;
}
#include <bits/stdc++.h>

using namespace std;

static constexpr int MOD = 1e9 + 7;

class Solution {
public:
    long long maximumPoints(vector<int>& vec, int cnt) {
        int mn = ranges::min(vec);
        if (cnt < mn) {
            return 0;
        }
        return (accumulate(vec.begin(), vec.end(), 0ll) + cnt) / mn - 1;

        /*
            int n = vec.size();
            ranges::sort(vec);

            long long ans = 0;
            for (int i = n - 1; i >= 0; --i) {
                ans += cnt / vec[0];
                cnt %= vec[0];
                if (ans == 0) {
                    break;
                }
                cnt += vec[i];
            }
            return ans;
        */
    }
};

int main() {
    Solution sol;

    return 0;
}
#include <bits/stdc++.h>

using namespace std;
using ll = long long;

constexpr int mod = 1e9 + 7;

class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        int sum = 0, ans = 0;
        int cnt1 = 0, cnt2 = 1; // ump[0] = 1
        for (int& v : arr) {
            sum += v;

            if (sum % 2 == 1) {
                cnt1++;
                ans = (ans + cnt2) % mod;
            } else {
                cnt2++;
                ans = (ans + cnt1) % mod;
            }
        }
        return ans;
    }
};

int main() {
    Solution sol;

    return 0;
}
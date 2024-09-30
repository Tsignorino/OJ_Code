#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        //* 之前的滑窗
        // int n = s.size(), ans = 0, cost = 0;
        // for (int l = 0, r = 0; r < n; ++r) {
        //     cost += abs(s[r] - t[r]);

        //     while (cost > maxCost) {
        //         cost -= abs(s[l] - t[l]);
        //         l++;
        //     }

        //     ans = max(ans, r - l + 1);
        // }

        // return ans;

        //* 受 424题 影响的滑窗
        int n = s.size();
        int l = 0, r = 0, cost = 0;
        while (r < n) {
            cost += abs(s[r] - t[r]);
            r++;

            if (cost > maxCost) {
                cost -= abs(s[l] - t[l]);
                l++;
            }
        }
        return r - l;
    }
};

int main() {
    Solution sol;

    string s("abcd"), t("bcdf");
    int maxCost = 3;
    cout << sol.equalSubstring(s, t, maxCost);

    return 0;
}
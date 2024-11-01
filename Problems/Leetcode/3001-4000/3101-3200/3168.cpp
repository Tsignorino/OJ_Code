#include <bits/stdc++.h>

using namespace std;

static constexpr int MOD = 1e9 + 7;

class Solution {
public:
    int minimumChairs(string s) {
        int ans = 0;
        int res = 0;
        for (char& ch : s) {
            if (ch == 'E') {
                res++;
            } else {
                res--;
            }
            ans = max(ans, res);
        }
        return ans;
    }
};

int main() {
    Solution sol;


    return 0;
}
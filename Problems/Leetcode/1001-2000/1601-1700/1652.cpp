#include <bits/stdc++.h>

using namespace std;

constexpr int MOD = 1e9 + 7;

class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) {
        int n = code.size();
        vector<int> vec(n);
        if (k == 0) {
            return vec;
        }

        int res = 0;
        for (int i = 0; i < n; ++i) {
            if (k > 0) {
                for (int j = i + 1; j <= i + k; ++j) {
                    vec[i] += code[j % n];
                }
            } else {
                for (int j = i - 1; j >= i + k; --j) {
                    vec[i] += code[(j + n) % n];
                }
            }
        }
        return vec;
    }
};

int main() {
    Solution sol;

    return 0;
}
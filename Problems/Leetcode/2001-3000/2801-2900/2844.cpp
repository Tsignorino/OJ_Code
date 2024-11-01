#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minimumOperations(string num) {
        int n = num.size();

        int ans = n;
        for (int i = n - 1; i >= 0; --i) {
            if (num[i] == '0') {
                ans = min(ans, n - 1);
                for (int j = i - 1; j >= 0; --j) {
                    if (num[j] == '0' || num[j] == '5') {
                        ans = min(ans, n - j - 2);
                        break;
                    }
                }
            }
            if (num[i] == '5') {
                for (int j = i - 1; j >= 0; --j) {
                    if (num[j] == '2' || num[j] == '7') {
                        ans = min(ans, n - j - 2);
                        break;
                    }
                }
            }
        }
        return ans;
    }
};

int main() {
    Solution sol;

    return 0;
}
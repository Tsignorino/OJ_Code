#include <bits/stdc++.h>

using namespace std;
using ll = long long;

class Solution {
public:
    int countKeyChanges(string s) {
        int ans = 0, n = s.size();
        for (int i = 1; i < n; ++i) {
            ans += (s[i] & 31) != (s[i - 1] & 31);
        }
        return ans;
    }
};

int main() {
    Solution sol;

    string s("aAbAcC");
    cout << sol.countKeyChanges(s);

    return 0;
}
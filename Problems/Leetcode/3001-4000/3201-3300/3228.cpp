#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxOperations(string s) {
        int ans = 0, cnt = 0;
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == '1') {
                cnt++;
            } else if (i && s[i - 1] == '1') {
                ans += cnt;
            }
        }
        // Or: 
        // for (int i = s.size() - 1; i >= 0; --i) {
        //     if (s[i] == '1') {
        //         ans += cnt;
        //     } else if (i && s[i - 1] == '1') {
        //         cnt++;
        //     }
        // }
        return ans;
    }
};

int main() {
    Solution sol;

    return 0;
}
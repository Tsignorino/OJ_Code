#include <bits/stdc++.h>

using namespace std;
using ll = long long;

class Solution {
public:
    int totalFruit(vector<int>& s) {
        // * fruits[i] 代表树的类型
        // * 寻找至多包含两种元素的最长连续子数组
        int n = s.size();
        unordered_map<int, int> ump;
        int ans = 0;
        for (int l = 0, r = 0; r < n; ++r) {
            ++ump[s[r]];
            while (ump.size() > 2) {
                auto iter = ump.find(s[l]);
                --iter->second;
                if (iter->second == 0) {
                    ump.erase(iter);
                }
                l++;
            }

            ans = max(ans, r - l + 1);
        }

        return ans;
    }
};

int main() {
    Solution sol;

    vector<int> fruits {1, 2, 1};
    cout << sol.totalFruit(fruits);

    return 0;
}
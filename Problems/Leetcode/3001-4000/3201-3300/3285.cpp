#include <bits/stdc++.h>

using namespace std;
using ll = long long;

class Solution {
public:
    vector<int> stableMountains(vector<int>& height, int threshold) {
        int n = height.size();
        vector<int> ans;
        for (int i = 1; i < n; ++i) {
            if (height[i - 1] > threshold) {
                ans.emplace_back(i);
            }
        }
        return ans;
    }
};

int main() {
    Solution sol;

    return 0;
}
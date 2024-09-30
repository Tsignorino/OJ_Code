#include <bits/stdc++.h>

using namespace std;

constexpr int MOD = 1e9 + 7;

class Solution {
public:
    int minimumOperationsToMakeKPeriodic(string word, int k) {
        int n = word.size();
        unordered_map<string, int> ump;
        int maxV = 0;
        for (int i = 0; i < n; i += k) {
            int& v = ump[word.substr(i, k)];
            maxV = max(maxV, ++v);
        }
        return n / k - maxV;
    }
};

int main() {
    Solution sol;
    string s("leetcodeleet");
    int k = 4;
    sol.minimumOperationsToMakeKPeriodic(s, k);

    return 0;
}
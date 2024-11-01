#include <bits/stdc++.h>

using namespace std;
using ll = long long;

class Solution {
public:
    int minExtraChar(string s, vector<string>& dictionary) {
        set<string> S(dictionary.begin(), dictionary.end());

        int n = s.size();
        vector<int> f(n + 1);
        for (int i = 0; i < n; ++i) {
            f[i + 1] = f[i] + 1;
            for (int j = 0; j <= i; ++j) {
                if (S.contains(s.substr(j, i - j + 1))) {
                    f[i + 1] = min(f[i + 1], f[j]);
                }
            }
        }
        return f[n];
    }
};

int main() {
    Solution sol;

    return 0;
}
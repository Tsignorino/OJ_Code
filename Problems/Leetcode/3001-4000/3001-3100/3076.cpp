#include <bits/stdc++.h>

using namespace std;
using ll = long long;

class Solution {
public:
    vector<string> shortestSubstrings(vector<string>& arr) {
        int n = arr.size();

        auto check = [&](int i, string& sub) {
            for (int j = 0; j < n; ++j) {
                if (j != i && arr[j].find(sub) != string::npos) {
                    return false;
                }
            }
            return true;
        };

        vector<string> ans(n);
        for (int i = 0; i < n; ++i) {
            int m = arr[i].size();
            string res;
            for (int k = 1; k <= m && res.empty(); ++k) {
                for (int j = k; j <= m; ++j) {
                    string t = arr[i].substr(j - k, k);
                    if ((res.empty() || t < res) && check(i, t)) {
                        res = t;
                    }
                }
            }

            ans[i] = res;
        }

        return ans;
    }
};
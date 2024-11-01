#include <bits/stdc++.h>

using namespace std;
using ll = long long;

static constexpr int MOD = 1e9 + 7;

class Solution {
public:
    vector<string> splitWordsBySeparator(vector<string>& words, char separator) {
        vector<string> ans;

        /* Solution 1 */
        for (string& word : words) {
            word += separator;
            string str;
            for (const char& c : word) {
                if (c != separator) {
                    str += c;
                } else {
                    if (!str.empty()) {
                        ans.emplace_back(std::move(str));
                        str.clear();
                    }
                }
            }
        }

        /* Solution 2 */
        for (string& word : words) {
            stringstream ss(word);
            string sub;
            while (getline(ss, sub, separator)) {
                if (!sub.empty()) {
                    ans.emplace_back(sub);
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
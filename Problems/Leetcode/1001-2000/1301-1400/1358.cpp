#include <bits/stdc++.h>

using namespace std;
using ll = long long;

class Solution {
public:
    // int numberOfSubstrings(string s) {
    //     int n = s.size();
    //     unordered_map<char, int> ump;

    //     int ans = 0;
    //     for (int l = 0, r = 0; r < n; ++r) {
    //         ump[s[r]]++;

    //         while (ump.size() == 3) {
    //             ump[s[l]]--;
    //             if (ump[s[l]] == 0) {
    //                 ump.erase(s[l]);
    //             }

    //             l++;
    //         }

    //         ans += l;
    //     }

    //     return ans;
    // }

    int numberOfSubstrings(string s) {
        int n = s.size(), ans = 0;
        int a[3] = {-1, -1, -1};

        for (int i = 0; i < n; ++i) {
            a[s[i] - 'a'] = i;
            ans += min({a[0], a[1], a[2]}) + 1;
        }

        return ans;
    }
};

int main() {
    Solution sol;

    string s("abcabc");
    cout << sol.numberOfSubstrings(s);

    return 0;
}
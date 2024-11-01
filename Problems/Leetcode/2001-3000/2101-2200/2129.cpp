#include <bits/stdc++.h>

using namespace std;
using ll = long long;

class Solution {
public:
    string capitalizeTitle(string title) {
        //* Solution 1
        // int n = title.size();
        // int i = 0, j = 0;
        // string s("");
        // while (i < n && j < n) {
        //     while (j < n && title[j] != ' ') {
        //         j++;
        //     }

        //     for (int k = i; k < j; ++k) {
        //         s += (j - i > 2 && k == i) ? toupper(title[k]) : tolower(title[k]);
        //     }
        //     if (j < n) {
        //         s += ' ';
        //     }
        //     i = ++j;
        // }
        // return s;

        //* Solution 2
        istringstream iss(title);
        string ans, s;
        while (iss >> s) {
            if (!ans.empty()) {
                ans += ' ';
            }

            if (s.size() > 2) {
                ans += toupper(s[0]);
                s = s.substr(1);
            }
            for (char ch : s) {
                ans += tolower(ch);
            }
        }
        return ans;
    }
};

int main() {
    string s("capiTalIze tHe titLe");

    Solution sol;
    sol.capitalizeTitle(s);

    return 0;
}
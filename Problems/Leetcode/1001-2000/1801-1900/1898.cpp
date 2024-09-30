#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maximumRemovals(string s, string p, vector<int>& removable) {
        int n = removable.size();
        int l = -1, r = n + 1; // 枚举 k 的范围
        while (l + 1 < r) {
            int mid = l + (r - l) / 2;

            string ss = s;
            for (int i = 0; i < mid; ++i) {
                ss[removable[i]] = 'A'; //* 变成不存在的字符，相当于移除，但不要改变原字符串
            }

            int p1 = 0, p2 = 0;
            while (p1 < ss.size() && p2 < p.size()) {
                if (ss[p1] == p[p2]) {
                    p2++;
                }
                p1++;
            }

            if (p2 == p.size()) {
                l = mid;
            } else {
                r = mid;
            }
        }

        return l;
    }
};

int main() {
    Solution sol;

    string s("abcacb"), p("ab");
    vector<int> removable {3, 1, 0};
    cout << sol.maximumRemovals(s, p, removable);

    return 0;
}
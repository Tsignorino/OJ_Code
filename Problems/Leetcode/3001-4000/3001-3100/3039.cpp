#include <bits/stdc++.h>

using namespace std;
using ll = long long;

class Solution {
public:
    string lastNonEmptyString_0(string s) {
        unordered_map<char, int> ump;
        int maxV = 1;
        for (const char& ch : s) {
            ump[ch]++;
            maxV = max(maxV, ump[ch]);
        }

        int n = s.size();
        string ss;
        for (int i = n; i >= 0; --i) {
            if (ump[s[i]]-- == maxV) {
                ss.push_back(s[i]);
            }
        }

        ranges::reverse(ss);
        return ss;
    }

public:
    string lastNonEmptyString_1(string s) {
        int cnt[26] {}, last[26] {};
        for (int i = 0; i < s.size(); i++) {
            int b = s[i] - 'a';
            cnt[b]++;
            last[b] = i;
        }

        // 注：也可以再遍历一次 s 直接得到答案，但效率不如下面，毕竟至多 26 个数
        vector<int> ids;
        int mx = ranges::max(cnt);
        for (int i = 0; i < 26; i++) {
            if (cnt[i] == mx) {
                ids.push_back(last[i]);
            }
        }
        ranges::sort(ids);

        string t(ids.size(), ' ');
        for (int i = 0; i < ids.size(); i++) {
            t[i] = s[ids[i]];
        }
        return t;
    }
};
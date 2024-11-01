#include <bits/stdc++.h>

using namespace std;

static constexpr int MOD = 1e9 + 7;

class Solution {
public:
    int garbageCollection(vector<string>& garbage, vector<int>& travel) {
        int ans = reduce(travel.begin(), travel.end()) * 3;
        for (string& g : garbage) {
            ans += g.length();
        }
        for (char c : {'M', 'P', 'G'}) {
            for (int i = garbage.size() - 1; i && garbage[i].find(c) == string::npos; i--) {
                ans -= travel[i - 1];
            }
        }
        return ans;
    }

    int garbageCollection_1(vector<string>& garbage, vector<int>& travel) {
        int ans = garbage[0].length();
        int sum_t = 0;
        int t_map[4] {};
        for (int i = 1; i < garbage.size(); i++) {
            string& s = garbage[i];
            ans += s.length();
            sum_t += travel[i - 1];
            for (char c : s) {
                ans += sum_t - t_map[c & 3];
                t_map[c & 3] = sum_t;
            }
        }
        return ans;
    }

    int garbageCollection_2(vector<string>& garbage, vector<int>& travel) {
        int ans = garbage[0].length();
        set<char> seen;
        for (int i = garbage.size() - 1; i; i--) {
            string& g = garbage[i];
            seen.insert(g.begin(), g.end());
            ans += g.length() + travel[i - 1] * seen.size();
        }
        return ans;
    }
};

class mySolution {
public:
    int garbageCollection(vector<string>& garbage, vector<int>& travel) {
        int n = garbage.size();
        vector<int> pre(n);
        for (int i = 0; i < n - 1; ++i) {
            pre[i + 1] = pre[i] + travel[i];
        }

        int id1 = 0; // M
        int id2 = 0; // P
        int id3 = 0; // G
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            ans += garbage[i].size();
            for (char& ch : garbage[i]) {
                if (ch == 'M') {
                    id1 = i;
                } else if (ch == 'P') {
                    id2 = i;
                } else {
                    id3 = i;
                }
            }
        }

        return pre[id1] + pre[id2] + pre[id3] + ans;
    }
};

int main() {
    Solution sol;

    return 0;
}
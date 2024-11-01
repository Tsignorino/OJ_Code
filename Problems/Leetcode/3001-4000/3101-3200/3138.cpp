#include <bits/stdc++.h>

using namespace std;

constexpr int MOD = 1e9 + 7;

class Solution {
public:
    int minAnagramLength(string s) {
        int n = s.size();
        int cnt[26] {};
        for (char c : s) {
            cnt[c - 'a']++;
        }

        // 检查子串的长度是否可能为 len
        auto check = [&](int len) {
            for (int i = 0; i < n; i += len) {
                int tmp[26] {};
                for (int j = 0; j < len; j++) {
                    tmp[s[i + j] - 'a']++;
                }

                for (int j = 0; j < 26; j++) {
                    if (tmp[j] * (n / len) != cnt[j]) {
                        return false;
                    }
                }
            }
            return true;
        };

        for (int i = 1; i <= n; i++) {
            if (n % i == 0 && check(i)) {
                return i;
            }
        }
        return -1;
    }
};

class Wrong_Solution { // 2024.5.5 数据太弱  hack数据：aabb（实际输出：2，预期输出：4）
public:
    int minAnagramLength(string s) {
        unordered_map<char, int> ump;
        for (char ch : s) {
            ump[ch]++;
        }

        int g = 0;
        for (auto& [_, v] : ump) {
            g = gcd(g, v);
        }

        int ans = 0;
        for (auto& [_, v] : ump) {
            ans += (v / g);
        }
        return ans;
    }
};

int main() {
    Solution sol;

    // "jjj"        1

    return 0;
}
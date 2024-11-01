#include <bits/stdc++.h>

using namespace std;
using ll = long long;

class Solution {
public:
    //* 正向：最多构造多少个回文串
    int maxPalindromesAfterOperations_0(vector<string>& words) {
        int ans = 0, total = 0, mask = 0;
        for (const string& word : words) {
            total += word.size();
            for (const char& ch : word) {
                mask ^= 1 << (ch - 'a');
            }
        }

        total -= __popcount(mask);

        // 按字符串长度从小到大排序
        ranges::sort(words, [](const string& a, const string& b) -> bool { return a.size() < b.size(); });

        // 看剩余的字符能够填多少个字符串
        for (const string& word : words) {
            // 先试着填充字符串
            total -= word.size() / 2 * 2;

            if (total < 0) { // 说明当前这个回文串无法填充完整
                break;
            }

            ans++;
        }

        return ans;
    }

public:
    //* 逆向：最多有多少个字符串不是回文
    // 如果每个字母的总出现次数均为偶数，那么所有字符串都可以是回文串
    // 否则，将出现次数为奇数的字符每个都取出来一个，构成一个集合
    //     如果集合大小小于奇数长度字符串的个数，正常放置
    //     否则，将未填充的剩余字符优先放入长度最长的字符串中
    //     （奇数长度的字符串中，中间已经填入了一个字符，所以奇数长度的字符串能容纳的字符数量为长度减 1）
    int maxPalindromesAfterOperations_1(vector<string>& words) {
        int ans = words.size();

        // 执行交换任意次数，相当于将所有字符取出再放回
        int cnt = 0, mask = 0;
        for (const string& word : words) {
            cnt += word.size() & 1; // 奇数长度字符串的数目

            for (const char& ch : word) { // 统计剩余的奇数字符的个数
                mask ^= 1 << (ch - 'a');
            }
        }

        // 按字符串长度从大到小排序
        ranges::sort(words, [](const string& a, const string& b) -> bool { return a.size() > b.size(); });

        int remain_odds = __popcount(mask) - cnt; // 向每个长度为奇数的字符串里面添加一个字符
        for (const string& word : words) {
            if (remain_odds <= 0) {
                break;
            }

            // 优先往长字符串里面加入字符（加入字符的数量：奇数减 1，偶数不变）
            // remain_odds -= word.size() - (word.size() & 1);
            remain_odds -= word.size() / 2 * 2;

            ans--; // 每填满一个长字符串，ans--
        }

        return ans;
    }
};
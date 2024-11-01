#include <bits/stdc++.h>

using namespace std;
using ll = long long;

class Solution_0 {
public:
    int bestTeamScore(vector<int>& scores, vector<int>& ages) {
        int n = scores.size();
        pair<int, int> a[n];
        for (int i = 0; i < n; ++i) {
            a[i] = {scores[i], ages[i]};
        }
        sort(a, a + n);

        vector<int> f(n);
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                if (a[j].second <= a[i].second) {
                    f[i] = max(f[i], f[j]);
                }
            }
            f[i] += a[i].first;
        }
        return ranges::max(f);
    }
};

class Solution_1 {
public:
    int bestTeamScore(vector<int>& scores, vector<int>& ages) {
        int n = scores.size();
        pair<int, int> a[n];
        for (int i = 0; i < n; ++i) {
            a[i] = {scores[i], ages[i]};
        }
        sort(a, a + n);

        int u = ranges::max(ages);
        int maxSum[u + 1];
        memset(maxSum, 0, sizeof(maxSum));
        for (auto& [score, age] : a) {
            maxSum[age] = *max_element(maxSum, maxSum + age + 1) + score;
        }
        return *max_element(maxSum, maxSum + u + 1);
    }
};

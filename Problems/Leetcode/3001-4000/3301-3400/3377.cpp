#include <bits/stdc++.h>

#include "debug.h"

using namespace std;
using ll = long long;

static constexpr int MOD = 1'000'000'007;

vector<int> isPrime;
vector<int> primes;
void sieve(int n) {
    isPrime.assign(n + 1, 1);
    isPrime[0] = isPrime[1] = 0;
    for (int i = 2; i <= n; ++i) {
        if (!isPrime[i]) {
            continue;
        }
        primes.emplace_back(i);
        for (auto j = i * 1ll * i; j <= n; j += i) {
            isPrime[j] = 0;
        }
    }
}

auto init = []() {
    sieve(1e4 + 10);
    return 0;
}();

/*

题目要求求出操作数值之和，相当于有权值的图
如果要求求出最小操作次数，相当于权值为 1，可以考虑 01-BFS

*/

class Solution {
public:
    int minOperations(int n, int m) {
        if (isPrime[n] || isPrime[m]) {
            return -1;
        }

        int len = to_string(n).size();
        vector<int> dis(pow(10, len), INT_MAX / 2);
        auto dijkstra = [&](int s = 0) {
            dis[s] = 0;

            using PII = pair<int, int>;
            priority_queue<PII, vector<PII>, greater<>> pq;
            pq.emplace(0, s); // dis[k], k
            while (!pq.empty()) {
                auto [d, cur] = pq.top();
                pq.pop();

                if (d > dis[cur]) {
                    continue;
                }

                int p = 1;
                for (int v = cur; v; v /= 10, p *= 10) {
                    int digit = v % 10;
                    if (digit > 0) {
                        int nxt = cur - p;
                        int nd = d + nxt;
                        if (!isPrime[nxt] && nd < dis[nxt]) {
                            dis[nxt] = nd;
                            pq.emplace(nd, nxt);
                        }
                    }
                    if (digit < 9) {
                        int nxt = cur + p;
                        int nd = d + nxt;
                        if (!isPrime[nxt] && nd < dis[nxt]) {
                            dis[nxt] = nd;
                            pq.emplace(nd, nxt);
                        }
                    }
                }
            }
            return 0;
        };
        dijkstra(n);

        return dis[m] == INT_MAX / 2 ? -1 : dis[m] + n;
    }
};

int main() {
    Solution sol;

    sol.minOperations(10, 12);

    return 0;
}
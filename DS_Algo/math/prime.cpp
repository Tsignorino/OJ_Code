#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#define N 10000

// * 块筛选  ——  计算不大于 n 的质数的总数量
int count_primes(int n) {
    const int S = 10000;

    vector<int> primes;
    int nsqrt = sqrt(n);
    vector<char> is_prime(nsqrt + 1, true);
    for (int i = 2; i <= nsqrt; i++) {
        if (is_prime[i]) {
            primes.push_back(i);
            for (int j = i * i; j <= nsqrt; j += i) is_prime[j] = false;
        }
    }

    int result = 0;
    vector<char> block(S);
    for (int k = 0; k * S <= n; k++) {
        fill(block.begin(), block.end(), true);

        int start = k * S;
        for (int& p : primes) {
            int start_idx = (start + p - 1) / p;
            int j = max(start_idx, p) * p - start;
            for (; j < S; j += p) block[j] = false;
        }
        if (k == 0) block[0] = block[1] = false;
        for (int i = 0; i < S && start + i <= n; i++) {
            if (block[i]) result++;
        }
    }

    return result;
}

// * Linear screen (Euler screen) ———— 让每个合数只被标记一次
vector<int> pri;
vector<int> isPrime(N + 1);
int phi[N];

void pre(int n) {
    phi[1] = 1;

    for (int i = 2; i <= n; ++i) {
        if (isPrime[i]) {
            pri.emplace_back(i);
            phi[i] = i - 1;
        }
        for (int& pri_j : pri) {
            if (i * pri_j > n) {
                break;
            }
            isPrime[i * pri_j] = 0;

            if (i % pri_j == 0) {
                phi[i * pri_j] = phi[i] * pri_j;
                break;
            }
            phi[i * pri_j] = phi[i] * phi[pri_j];
        }
    }
}
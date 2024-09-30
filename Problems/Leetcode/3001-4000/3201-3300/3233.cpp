#include <bits/stdc++.h>

using namespace std;

#define N 100'000
vector<int> isPrime(N + 1, 1);
auto init = []() {
    isPrime[0] = isPrime[1] = 0;
    for (int i = 2; i <= N; ++i) {
        if (!isPrime[i]) {
            continue;
        }
        for (long long j = i * 1ll * i; j <= N; j += i) {
            isPrime[j] = 0;
        }
    }
    return 0;
}();

class Solution {
public:
    int nonSpecialCount(int l, int r) {
        vector<long long> vec;
        for (int i = 0; i < N; ++i) {
            if (isPrime[i]) {
                vec.emplace_back(i * 1ll * i);
            }
        }
        return r - l + 1 - (ranges::upper_bound(vec, r) - ranges::lower_bound(vec, l));
    }
};

int main() {
    Solution sol;

    return 0;
}
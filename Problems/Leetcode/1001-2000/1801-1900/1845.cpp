#include <bits/stdc++.h>

#include "_debug.h"

using namespace std;
using ll = long long;

static constexpr int MOD = 1'000'000'007;

class SeatManager {
    int seats = 0;
    priority_queue<int, vector<int>, greater<>> q;

public:
    SeatManager(int n) {}

    int reserve() {
        if (!q.empty()) {
            int v = q.top();
            q.pop();
            return v;
        }
        return ++seats;
    }

    void unreserve(int seatNumber) { q.emplace(seatNumber); }
};

/**
 * Your SeatManager object will be instantiated and called as such:
 * SeatManager* obj = new SeatManager(n);
 * int param_1 = obj->reserve();
 * obj->unreserve(seatNumber);
 */

#include <bits/stdc++.h>

using namespace std;
using ll = long long;

constexpr int mod = 1e9 + 7;

class SnapshotArray {
    int cur_id = 0;
    unordered_map<int, vector<pair<int, int>>> ump;

public:
    SnapshotArray(int length) {}

    void set(int index, int val) { ump[index].emplace_back(cur_id, val); }

    int snap() { return cur_id++; }

    int get(int index, int snap_id) {
        auto& p = ump[index];
        int j = ranges::lower_bound(p, make_pair(snap_id + 1, 0)) - p.begin() - 1;
        return j >= 0 ? p[j].second : 0;
    }
};

/**
 * Your SnapshotArray object will be instantiated and called as such:
 * SnapshotArray* obj = new SnapshotArray(length);
 * obj->set(index,val);
 * int param_2 = obj->snap();
 * int param_3 = obj->get(index,snap_id);
 */
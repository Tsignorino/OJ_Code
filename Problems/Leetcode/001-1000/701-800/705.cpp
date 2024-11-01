#include <bits/stdc++.h>

using namespace std;

class MyHashSet {
private:
    vector<list<int>> data;
    static constexpr int base = 769;
    static int hash(int key) { return key % base; }

public:
    MyHashSet() : data(base) {}

    void add(int key) {
        int h = hash(key);
        for (auto iter = data[h].begin(); iter != data[h].end(); ++iter) {
            if (*iter == key) {
                return;
            }
        }
        data[h].emplace_back(key);
    }

    void remove(int key) {
        int h = hash(key);
        for (auto iter = data[h].begin(); iter != data[h].end(); ++iter) {
            if (*iter == key) {
                data[h].erase(iter);
                return;
            }
        }
    }

    bool contains(int key) {
        int h = hash(key);
        for (auto iter = data[h].begin(); iter != data[h].end(); ++iter) {
            if (*iter == key) {
                return true;
            }
        }
        return false;
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */
#include <bits/stdc++.h>

using namespace std;

class FrequencyTracker {
private:
    unordered_map<int, int> cnt, freq;

public:
    FrequencyTracker() {}

    void add(int number) {
        freq[cnt[number]]--;
        cnt[number]++;
        freq[cnt[number]]++;
    }

    void deleteOne(int number) {
        if (cnt[number] == 0) {
            return;
        }
        
        freq[cnt[number]]--;
        cnt[number]--;
        freq[cnt[number]]++;
    }

    bool hasFrequency(int frequency) { return freq[frequency]; }
};

/**
 * Your FrequencyTracker object will be instantiated and called as such:
 * FrequencyTracker* obj = new FrequencyTracker();
 * obj->add(number);
 * obj->deleteOne(number);
 * bool param_3 = obj->hasFrequency(frequency);
 */
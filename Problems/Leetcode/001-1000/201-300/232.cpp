#include <bits/stdc++.h>

using namespace std;
using ll = long long;

class MyQueue {
    stack<int> in, out;

    void inToOut() {
        while (!in.empty()) {
            out.push(in.top());
            in.pop();
        }
    }

public:
    MyQueue() {}

    void push(int x) { in.push(x); }

    int pop() {
        if (out.empty()) {
            inToOut();
        }

        int v = out.top();
        out.pop();
        return v;
    }

    int peek() {
        if (out.empty()) {
            inToOut();
        }
        
        return out.top();
    }

    bool empty() {
        return in.empty() && out.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */
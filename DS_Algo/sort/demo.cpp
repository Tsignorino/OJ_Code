#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void selection_sort(int* a, int n) {
    if (n < 2) {
        return;
    }

    for (int i = 0; i < n - 1; ++i) {
        int idx = i;
        for (int j = i + 1; j < n; ++j) {
            if (a[j] < a[idx]) {
                idx = j;
            }
        }

        if (idx != i) {
            swap(a[i], a[idx]);
        }
    }
}

void bubble_sort(int* a, int n) {
    if (n < 2) {
        return;
    }

    bool flag = true;
    while (flag) {
        flag = false;

        for (int i = 0; i < n - 1; ++i) {
            if (a[i] > a[i + 1]) {
                flag = true;
                swap(a[i], a[i + 1]);
            }
        }
    }
}

void insertion_sort(int* a, int n) {
    if (n < 2) {
        return;
    }

    for (int i = 1; i < n; ++i) {
        int v = a[i];

        int j = i - 1;
        while (j >= 0 && a[j] > v) {
            a[j + 1] = a[j];
            j--;
        }

        a[j + 1] = v;
    }
}

void half_insertion_sort(int* a, int n) {
    if (n < 2) {
        return;
    }

    for (int i = 1; i < n; ++i) {
        int v = a[i];

        auto idx = upper_bound(a, a + i, v) - a;
        memmove(a + idx + 1, a + idx, (i - idx) * sizeof(int));

        a[idx] = v;
    }
}

const int N = 10'010;
const int W = 10'010;
int a[N], b[N], cnt[W] {}, n, w;
void counting_sort() {
    for (int i = 0; i < n; ++i) {
        cnt[a[i]]++;
    }
    for (int i = 1; i <= w; ++i) {
        cnt[i] += cnt[i - 1];
    }

    for (int i = n - 1; i >= 0; --i) {
        b[cnt[a[i]]--] = a[i];
    }
}

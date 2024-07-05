#include <algorithm>
#include <iostream>

using namespace std;

struct tree {
    int h, a, t;
};

tree trees[200005];

bool cmp(const tree &f, const tree &s) { return f.t < s.t; }

void farm() {
    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> trees[i].h;
    }
    for (int i = 0; i < n; i++) {
        cin >> trees[i].a;
    }
    for (int i = 0; i < n; i++) {
        cin >> trees[i].t;
    }

    sort(trees, trees + n, cmp);

    if (n == 1) {
        cout << 0 << endl;
        return;
    }

    bool zero = true;
    for (int i=0; i<n-1; i++) {
        if (trees[i].h <= trees[i+1].h) {
            zero = false;
        }
    }

    if (zero) {
        cout << 0 << endl;
        return;
    }

    int left = 0;
    int right = 1000000005;
    for (int i = 0; i < n - 1; i++) {
        if (trees[i].a == trees[i + 1].a) {
            if (trees[i].h <= trees[i + 1].h) {
                cout << -1 << endl;
                return;
            }
        }

        if (trees[i].a > trees[i + 1].a) {
            left = max(left,
                       (trees[i + 1].h - trees[i].h) / (trees[i].a - trees[i + 1].a) + 1);
        }

        if (trees[i].a < trees[i + 1].a) {
            if ((trees[i + 1].h - trees[i].h) % (trees[i].a - trees[i + 1].a) == 0) {
                right = min(
                            right,
                            (trees[i + 1].h - trees[i].h) / (trees[i].a - trees[i + 1].a) - 1);
            } else {
                right = min(right, (trees[i + 1].h - trees[i].h) /
                            (trees[i].a - trees[i + 1].a));
            }
        }
    }

    if (right < left) {
        cout << -1 << endl;
    } else {
        cout << left << endl;
    }
}

int main() {
    int z;
    cin >> z;
    for (int i = 0; i < z; i++) {
        farm();
    }
}

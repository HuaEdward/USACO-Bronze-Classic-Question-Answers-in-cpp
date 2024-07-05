#include <algorithm>
#include <iostream>

using namespace std;

int n, k;
bool h[55][55];
int cnt;

void walking(int x, int y, int direction, int num) {
    if (num > k) {
        return;
    }
    if (num == k && x != n - 1 && y != n - 1) {
        return;
    }
    
    if (x == n - 1 && y == n - 1) {
        cnt++;
        return;
    }
    
    if (x + 1 < n && h[x + 1][y] == false) {
        if (direction == 1) {
            walking(x + 1, y, 0, num + 1);
        } else {
            walking(x + 1, y, 0, num);
        }
    }
    
    if (y + 1 < n && h[x][y + 1] == false) {
        if (direction == 0) {
            walking(x, y + 1, 1, num + 1);
        } else {
            walking(x, y + 1, 1, num);
        }
    }
}

void process() {
    cnt = 0;
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            char c;
            cin >> c;
            if (c == 'H') {
                h[i][j] = true;
            } else {
                h[i][j] = false;
            }
        }
    }
    walking(0, 0, 2, 0);
    cout << cnt << endl;
}

int main() {
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        process();
    }
}

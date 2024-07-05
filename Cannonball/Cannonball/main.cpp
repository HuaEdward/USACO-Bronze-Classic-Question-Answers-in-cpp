
#include <algorithm>
#include <iostream>

using namespace std;

int position[100005][2];
bool broken[100005];

int main() {
    int n;
    cin >> n;
    int start;
    cin >> start;
    for (int i=0; i<n; i++) {
        cin >> position[i][0] >> position[i][1];
    }

    int location = start-1;
    int value = 1;
    bool directRight = true;
    int count = 0;
    while (location < n && location >= 0 && count < 1e8) {
        if (position[location][0] == 0) {
            value = value + position[location][1];
            if (directRight) {
                directRight = false;
            } else {
                directRight = true;
            }
        }
        if (position[location][0] == 1) {
            if (value >= position[location][1]) {
                broken[location] = true;
            }
        }
        if (directRight) {
            location = location + value;
        } else {
            location = location - value;
        }
        count ++;
    }

    int ans = 0;
    for (int i=0; i<n; i++) {
        if (broken[i]) {
            ans++;
        }
    }

    cout << ans;
}


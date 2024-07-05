#include <iostream>
#include <algorithm>

#define int long long

using namespace std;

int cows[200005];

signed main() {
    int n;
    cin >> n;
    for (int i=0; i<n; i++) {
        cin >> cows[i];
    }

    int plusAmt = 0;
    int plusTimes = 0;
    int minusAmt = 0;
    int minusTimes = 0;
    int ans=0;
/*
    if (cows[0] != 0) {
        int x = 0-cows[0];

        if (cows[0] > 0) {
            minusAmt += x - n + 1;
            minusTimes ++;
        } else {
            plusAmt += x + n - 1;
            plusTimes ++;
        }

        ans ++;
    }

*/
    for (int i=0; i<n; i++) {
        cows[i] = cows[i] + (plusAmt - (n - i - 1) * plusTimes) + (minusAmt + (n - i - 1) * minusTimes);

        ans += abs(cows[i]);

        if (cows[i] > 0) {
            minusAmt += -1 * cows[i] * (n - i);
            minusTimes += abs(cows[i]);
        }
        if (cows[i] < 0) {
            plusAmt += -1 * cows[i] * (n - i);
            plusTimes += abs(cows[i]);
        }
    }

    cout << ans;
}

#include <iostream>

#define int long long

using namespace std;

int days[100005];

signed main() {
    int n, k;
    cin >> n >> k;

    for (int i=0; i<n; i++) {
        cin >> days[i];
    }

    int ans = 0;
    for (int i=0; i<n; i++) {
        if (days[i+1] - days[i] <= k+1 && days[i+1] - days[i] > 0) {
            int j = i+1;
            while (days[j+1] - days[j] > 0 && days[j+1] - days[j] <= k+1 && j < n) {
                j++;
            }
            ans += days[j]-days[i]+1+k;
            i=j;
        } else {
            ans += 1+k;
        }
    }

    cout << ans;
}

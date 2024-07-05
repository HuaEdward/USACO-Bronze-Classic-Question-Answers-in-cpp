
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

void baseIO(string s) {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  freopen((s + ".in").c_str(), "r", stdin);
  freopen((s + ".out").c_str(), "w", stdout);
}

int cows[105];
vector<int> from [105];

int main() {
    baseIO("hoofball");
    int n;
    cin >> n;
    for (int i=0; i<n; i++) {
        cin >> cows[i];
    }
    sort(cows, cows+n);

    from[1].push_back(0);
    from[n-1].push_back(n-2);
    for (int i=1; i<n-1; i++) {
        if (cows[i] - cows[i-1] <= cows[i+1] - cows[i]) {
            from[i-1].push_back(i);
        } else if (cows[i] - cows[i-1] > cows[i+1] - cows[i]) {
            from[i+1].push_back(i);
        }
    }

    int ans = 0;
    for (int i=0; i<n-1; i++) {
        if (from[i].size() == 0) {
            ans ++;
        }

        if (from[i].size() == 1 && from[i+1].size() == 1 && from[i][0] == i+1 && from[i+1][0] == i) {
            ans ++;
        }
    }
    if (from[n-1].size() == 0) {
        ans ++;
    }

    cout << ans;
}


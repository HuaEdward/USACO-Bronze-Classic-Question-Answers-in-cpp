#include <iostream>
#include <vector>

#define int long long

using namespace std;

int cows[200005];
vector<int> to[200005];
vector<int> ffrom[200005];

vector<int> noFromIndex;

signed main() {
    int n, m;
    cin >> n >> m;
    
    for (int i = 0; i < n; i++) {
        char dir;
        cin >> dir;
        if (dir == 'R') {
            if (i == n - 1) {
                ffrom[0].push_back(i);
                to[i].push_back(0);
            } else {
                ffrom[i + 1].push_back(i);
                to[i].push_back(i + 1);
            }
        } else if (dir == 'L') {
            if (i == 0) {
                ffrom[n - 1].push_back(0);
                to[0].push_back(n - 1);
            } else {
                ffrom[i - 1].push_back(i);
                to[i].push_back(i - 1);
            }
        }
    }
    
    int total = 0;
    for (int i = 0; i < n; i++) {
        cin >> cows[i];
        total += cows[i];
    }
    
    for (int i = 0; i < n; i++) {
        if (ffrom[i].size() == 0) {
            noFromIndex.push_back(i);
        }
    }
    
    int totalLoss = 0;
    for (int i = 0; i < noFromIndex.size(); i++) {
        int loss = 0;
        int k = noFromIndex[i];
        int amount = m;
        while (true) {
            if (ffrom[k].size() > 1) {
                break;
            }
            loss += min(cows[k], amount);
            amount -= min(cows[k], amount);
            if (amount == 0) {
                break;
            }
            k = to[k][0];
        }
        totalLoss += loss;
    }
    
    cout << total - totalLoss;
}

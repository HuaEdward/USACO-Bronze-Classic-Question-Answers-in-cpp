#include <algorithm>
#include <iostream>

using namespace std;

pair<int, int> cows[105];

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> cows[i].first >> cows[i].second;
    }
    sort(cows, cows + n);
    
    int ans = 0;
    for (int i = 0; i < n; i++) {
        ans = max(ans, cows[i].first) + cows[i].second;
    }
    
    cout << ans;
}

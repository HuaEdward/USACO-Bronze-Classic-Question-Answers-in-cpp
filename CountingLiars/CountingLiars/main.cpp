#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<long long> G;
vector<long long> L;

int main() {
    int n;
    cin >> n;
    
    for (int i=0; i<n; i++) {
        char a;
        cin >> a;
        if (a == 'G') {
            int b;
            cin >> b;
            G.push_back(b);
        }
        if (a == 'L') {
            int b;
            cin >> b;
            L.push_back(b);
        }
    }
    
    int ans = 100000;
    for (auto g : G) {
        int numG = 0;
        for (auto l : L) {
            if (l < g) {
                numG++;
            }
        }
        for (auto g2 : G) {
            if (g2 > g) {
                numG++;
            }
        }
        ans = min(ans, numG);
    }
    
    for (auto l : L) {
        int numL = 0;
        for (auto g : G) {
            if (l < g) {
                numL++;
            }
        }
        for (auto l2 : L) {
            if (l2 < l) {
                numL++;
            }
        }
        ans = min(ans, numL);
    }
    
    cout << ans;
}

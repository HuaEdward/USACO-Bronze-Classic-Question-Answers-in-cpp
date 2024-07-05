#include <iostream>
#include <algorithm>

using namespace std;

int cows[105];
int sortedNum = 1;
int ans;

void baseIO(string s) {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  freopen((s + ".in").c_str(), "r", stdin);
  freopen((s + ".out").c_str(), "w", stdout);
}

int main() {
    baseIO("sleepy");
    
    int n;
    cin >> n;
    for (int i=0; i<n; i++) {
        cin >> cows[i];
    }
    
    bool sorted = true;
    for (int i=n-2; i>=0; i--) {
        if (cows[i] < cows[i+1] && sorted) {
            sortedNum ++;
        } else {
            sorted = false;
            break;
        }
    }
    
    ans = n - sortedNum;
    
    cout << ans;
}

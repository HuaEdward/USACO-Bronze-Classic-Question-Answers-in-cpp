#include <iostream>

using namespace std;

char cows[11][11];

void baseIO(string s) {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  freopen((s + ".in").c_str(), "r", stdin);
  freopen((s + ".out").c_str(), "w", stdout);
}

int main() {
    baseIO("cowtip");
    int n;
    cin >> n;
    
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            cin >> cows[i][j];
        }
    }
    
    int ans = 0;
    for (int i=n-1; i>=0; i--) {
        for (int j=n-1; j>=0; j--) {
            if (cows[i][j] == '1') {
                for (int a=0; a<=i; a++) {
                    for (int b=0; b<=j; b++) {
                        cows[a][b] = (cows[a][b] - '0' + 1) % 2 + '0';
                    }
                }
                ans ++;
            }
        }
    }
    
    cout << ans;
}

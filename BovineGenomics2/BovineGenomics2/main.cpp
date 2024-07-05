#include <iostream>

using namespace std;

int n, m;
char spotCows[105][105];
char plainCows[105][105];

void baseIO(string s) {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  freopen((s + ".in").c_str(), "r", stdin);
  freopen((s + ".out").c_str(), "w", stdout);
}

int main() {
    //baseIO("cownomics");
    
    cin >> n >> m;
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            cin >> spotCows[i][j];
        }
    }
    
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            cin >> plainCows[i][j];
        }
    }
    
    int ans = 0;
    for (int j=0; j<m; j++) {
        int same = n*n*n;
        for (int a=0; a<n; a++) {
            for (int b=0; b<n; b++) {
                if (spotCows[a][j] != plainCows[b][j]) {
                    same--;
                }
            }
        }
        if (same == 0) {
            ans ++;
        }
    }
    
    cout << ans;
}

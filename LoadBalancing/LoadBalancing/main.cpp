#include <iostream>

using namespace std;

int x[105];
int y[105];
int ans = 1000000;

void baseIO(string s) {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  freopen((s + ".in").c_str(), "r", stdin);
  freopen((s + ".out").c_str(), "w", stdout);
}

int main() {
    baseIO("balancing");
    int n, b;
    cin >> n >> b;
    
    for (int i=0; i<n; i++) {
        cin >> x[i] >> y[i];
    }
    
        int checkX = 0;
        int checkY = 0;
        for (int j=0; j<n; j++) {
            for (int k=0; k<n; k++) {
                checkX = x[j] + 1;
                checkY = y[k] + 1;
                int a=0;
                int b=0;
                int c=0;
                int d=0;
                int m=0;
                for (int p=0; p<n; p++) {
                    if (x[p] > checkX && y[p] > checkY) {
                        a++;
                    }
                    if (x[p] > checkX && y[p] < checkY) {
                        b++;
                    }
                    if (x[p] < checkX && y[p] < checkY) {
                        c++;
                    }
                    if (x[p] < checkX && y[p] > checkY) {
                        d++;
                    }
                }
                m = max(max(a, b), max(c, d));
                ans = min(ans, m);
            }
        }
    
    cout << ans;
}

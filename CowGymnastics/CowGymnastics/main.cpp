#include <iostream>

using namespace std;

int k, n;
int gym[11][21];
int greaterCow[21][21];

void baseIO(string s) {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  freopen((s + ".in").c_str(), "r", stdin);
  freopen((s + ".out").c_str(), "w", stdout);
}

int main() {
    baseIO("gymnastics");
    cin >> k >> n;
    for (int i=0; i<k; i++) {
        for (int j=0; j<n; j++) {
            cin >> gym[i][j];
        }
    }
    
    for (int l=0; l<k; l++) {
        for (int i=0; i<n; i++) {
            for (int j=i+1; j<n; j++) {
                int a=gym[l][i];
                int b=gym[l][j];
                greaterCow[a][b]++;
                greaterCow[b][a]--;
            }
        }
    }
    
    int ans=0;
    for (int i=0; i<21; i++) {
        for (int j=0; j<21; j++) {
            if (greaterCow[i][j] == k || greaterCow[i][j] == -k) {
                ans++;
            }
        }
    }
    cout << ans / 2;
}

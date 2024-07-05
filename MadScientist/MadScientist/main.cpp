
#include <iostream>

using namespace std;

void baseIO(string s) {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  freopen((s + ".in").c_str(), "r", stdin);
  freopen((s + ".out").c_str(), "w", stdout);
}

int main() {
    baseIO("breedflip");
    int n;
    cin >> n;
    string a, b;
    cin >> a >> b;
    
    int ans = 0;
    for (int i=0; i<n; i++) {
        if (a[i] != b[i]) {
            int j = i+1;
            while (j<n && a[j] != b[j]) {
                j++;
            }
            i = j;
            ans ++;
        }
    }
    
    cout << ans;
}

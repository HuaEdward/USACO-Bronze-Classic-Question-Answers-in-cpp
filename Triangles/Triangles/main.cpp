//
//  main.cpp
//  Triangles
//
//  Created by Edward Hu on 2024-04-18.
//

#include <iostream>
#include <vector>

using namespace std;

int x[101];
int y[101];
vector<int> areas;

void baseIO(string s) {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  freopen((s + ".in").c_str(), "r", stdin);
  freopen((s + ".out").c_str(), "w", stdout);
}

int main() {
    baseIO("triangles");
    int n=0;
    cin >> n;
    for (int i=0; i<n; i++) {
        cin >> x[i] >> y[i];
    }
    
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            for (int t=0; t<n; t++) {
                if (y[i]==y[j] && x[i] == x[t]) {
                    int d = abs(x[j]-x[i]);
                    areas.push_back(d*abs(y[t]-y[i]));
                }
            }
        }
    }
    
    int ans=0;
    for (int i : areas) {
        ans = max(ans, i);
    }
    
    cout << ans;
}

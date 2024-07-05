//
//  main.cpp
//  Blocked Billboard
//
//  Created by Edward Hu on 2024-04-09.
//

#include <iostream>

using namespace std;

bool space[2005][2005];

void baseIO(string s) {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  freopen((s + ".in").c_str(), "r", stdin);
  freopen((s + ".out").c_str(), "w", stdout);
}

int main() {
    baseIO("billboard");
    
    for (int r=0; r<2; r++) {
        int x_1, y_1, x_2, y_2;
        cin >> x_1 >> y_1 >> x_2 >> y_2;
        for (int i=x_1 + 1001; i<x_2 + 1001; i++) {
            for (int j=y_1 + 1001; j<y_2 + 1001; j++) {
                space[i][j] = true;
            }
        }
    }
    
    int X_1, Y_1, X_2, Y_2;
    cin >> X_1 >> Y_1 >> X_2 >> Y_2;
    for (int i=X_1 + 1001; i<X_2 + 1001; i++) {
        for (int j=Y_1 + 1001; j<Y_2 + 1001; j++) {
            space[i][j] = false;
        }
    }
    
    int ans = 0;
    
    for (int i=0; i<2005; i++) {
        for (int j=0; j<2005; j++) {
            if (space[i][j] == true) {
                ans ++;
            }
        }
    }
    
    cout << ans;
}

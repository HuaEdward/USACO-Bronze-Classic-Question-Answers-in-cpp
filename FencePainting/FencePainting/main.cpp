//
//  main.cpp
//  FencePainting
//
//  Created by Edward Hu on 2024-04-08.
//

#include <iostream>

using namespace std;

bool fence[105];

void baseIO(string s) {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  freopen((s + ".in").c_str(), "r", stdin);
  freopen((s + ".out").c_str(), "w", stdout);
}

int main() {
    baseIO("paint");
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    for (int i=a; i<b; i++) {
        fence[i] = true;
    }
    
    for (int i=c; i<d; i++) {
        fence[i] = true;
    }
    
    int ans = 0;
    for (int i=0; i<101; i++) {
        if (fence[i] == true) {
            ans ++;
        }
    }
    
    cout << ans;
}

//
//  main.cpp
//  TheBovineShuffle
//
//  Created by Edward Hu on 2024-05-12.
//

#include <iostream>

using namespace std;

int example1[105];
int example2[105];
int sequence[105];
int ID[105];
int ans[105];

void baseIO(string s) {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  freopen((s + ".in").c_str(), "r", stdin);
  freopen((s + ".out").c_str(), "w", stdout);
}

int main() {
    baseIO("shuffle");
    int n;
    cin >> n;
    
    for (int i=1; i<n+1; i++) {
        example1[i] = i;
        example2[i] = i;
    }
    
    for (int i=1; i<n+1; i++) {
        cin >> sequence[i];
    }
    
    for (int i=1; i<n+1; i++) {
        cin >> ID[i];
    }
    
    for (int i=0; i<3; i++) {
        for (int j=1; j<n+1; j++) {
            example2[sequence[j]] = example1[j];
        }
        for (int a=1; a<n+1; a++) {
            example1[a] = example2[a];
        }
    }
    
    for (int i=1; i<n+1; i++) {
        ans[example2[i]] = ID[i];
    }
    
    for (int i=1; i<n+1; i++) {
        cout << ans[i] << endl;
    }
}

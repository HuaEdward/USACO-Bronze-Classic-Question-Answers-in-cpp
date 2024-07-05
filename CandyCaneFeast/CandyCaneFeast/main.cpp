//
//  main.cpp
//  CandyCaneFeast
//
//  Created by Edward Hu on 2024-05-09.
//

#include <iostream>
#include <vector>

#define int long long

using namespace std;

int normalCows[200005];
vector<int> cows[2];
int candies[200005];

signed main() {
    int n, m;
    cin >> n >> m;
    
    for (int i=0; i<n; i++) {
        cin >> normalCows[i];
    }
    
    for (int i=0; i<m; i++) {
        cin >> candies[i];
    }
    
    for (int i=0; i<m; i++) {
        int h=0;
        for (int j=0; j<n; j++) {
            if (normalCows[j] <= h) {
                continue;
            } else if (normalCows[j] > h && normalCows[j] <= candies[i]) {
                int temp = normalCows[j];
                normalCows[j] = 2*normalCows[j] - h;
                h = temp;
            } else if (normalCows[j] > candies[i]) {
                normalCows[j] = normalCows[j] + candies[i] - h;
                break;
            }
        }
    }
    
    for (int i=0; i<n; i++) {
        cout << normalCows[i] << endl;
    }
}

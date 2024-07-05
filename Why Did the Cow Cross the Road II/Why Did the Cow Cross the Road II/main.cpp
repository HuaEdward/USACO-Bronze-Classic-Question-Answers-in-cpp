//
//  main.cpp
//  Why Did the Cow Cross the Road II
//
//  Created by Edward Hu on 2024-04-16.
//

#include <iostream>
#include <vector>

using namespace std;

string cows;
vector<int> points[26];

void baseIO(string s) {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  freopen((s + ".in").c_str(), "r", stdin);
  freopen((s + ".out").c_str(), "w", stdout);
}

int main() {
    baseIO("circlecross");
    cin >> cows;
    for (int i=0; i<cows.size()*2; i++) {
        for (char j='A'; j<='Z'; j++) {
            if (cows[i] == j) {
                points[j-'A'].push_back(i);
            }
        }
    }
    
    int ans=0;
    for (int i=0; i<26; i++) {
        for (int j=i+1; j<26; j++) {
            if (points[i][0] < points[j][0] && points[j][0] < points[i][1] && points[j][1] > points[i][1]) {
                ans ++;
            } else if (points[j][0] < points[i][0] && points[i][0] < points[j][1] && points[j][1] < points[i][1]) {
                ans ++;
            } else {
                continue;
            }
        }
    }
    
    cout << ans;
}

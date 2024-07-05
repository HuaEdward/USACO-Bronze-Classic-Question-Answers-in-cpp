#include <iostream>
#include <algorithm>

using namespace std;

int cows[3];

void baseIO(string s) {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  freopen((s + ".in").c_str(), "r", stdin);
  freopen((s + ".out").c_str(), "w", stdout);
}

int main() {
    baseIO("herding");
    for (int i=0; i<3; i++) {
        cin >> cows[i];
    }
    sort(cows, cows+3);
    
    int min = 0;
    if (cows[2] - cows[1] == 2 || cows[1] - cows[0] == 2) {
        min = 1;
    } else if (cows[1]-cows[0] == 1 && cows[2] - cows[1] == 1){
        min = 0;
    } else {
        min = 2;
    }
    cout << min << endl;
    
    int max = 0;
    /*while (cows[1]-cows[0] != 1 || cows[2] - cows[1] != 1) {
        if (cows[2]-cows[1] >= cows[1]-cows[0]) {
            cows[0] = cows[1]+1;
            max++;
        } else if (cows[2]-cows[1] < cows[1]-cows[0]) {
            cows[2] = cows[1]-1;
            max++;
        }
        sort(cows, cows+3);
    }*/
    if (cows[2]-cows[1] >= cows[1]-cows[0]) {
        max = cows[2]-cows[1]-1;
    } else if (cows[2]-cows[1] < cows[1]-cows[0]) {
        max = cows[1]-cows[0]-1;
    }
    
    cout << max;
}

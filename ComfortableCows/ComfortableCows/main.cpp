#include <iostream>
#include <algorithm>

using namespace std;

int cows[1005][1005];
bool full[1005][1005];
bool comfy[1005][1005];
bool placed[1005][1005];

int check(int x, int y) {
    if (placed[x][y]) {
        int num = 0;
        if (cows[x][y] == 3 && !comfy[x][y]) {
            num ++;
            comfy[x][y] = true;
        }
        if (cows[x][y] == 4 && !full[x][y]) {
            num --;
            full[x][y] = true;
            comfy[x][y] = false;
        }
        return num;
    } else {
        return 0;
    }
}

int main() {
    int n;
    cin >> n;
    
    int ans=0;
    for (int i=0; i<n; i++) {
        int x, y;
        cin >> x >> y;
        placed[x][y] = true;
        if (x+1 < n) {
            cows[x+1][y] ++;
        }
        if (x-1 >= 0) {
            cows[x-1][y] ++;
        }
        if (y+1 < n) {
            cows[x][y+1] ++;
        }
        if (y-1 >= 0) {
            cows[x][y-1] ++;
        }
        
        if (x+1 < n) {
            ans += check(x+1, y);
        }
        if (x-1 >= 0) {
            ans += check(x-1, y);
        }
        if (y+1 < n) {
            ans += check(x, y+1);
        }
        if (y-1 >= 0) {
            ans += check(x, y-1);
        }
        
        cout << ans << endl;
    }
}

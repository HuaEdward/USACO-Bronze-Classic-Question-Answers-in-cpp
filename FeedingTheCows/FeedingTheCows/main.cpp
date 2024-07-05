#include <iostream>

using namespace std;

int cows[100005];
bool noGrassG[100005];
bool noGrassH[100005];
//G0 H1
int grass[100005];

void process(){
    int n, k;
    cin >> n >> k;
    for (int i=0; i<n; i++) {
        char c;
        cin >> c;
        if (c == 'G') {
            cows[i] = 0;
        } else {
            cows[i] = 1;
        }
        grass[i] = 0;
        noGrassG[i] = false;
        noGrassH[i] = false;
    }
    
    for (int i=0; i<n; i++) {
        if (cows[i] == 0 && !noGrassG[i]) {
            if (i+k >= n) {
                if (grass[n-1] == 0) {
                    grass[n-1] = 10;
                } else {
                    grass[n-2] = 10;
                }
                for (int j=i; j<n; j++) {
                    noGrassG[j] = true;
                }
            } else {
                grass[i+k] = 10;
                for (int j=i; j<=i+2*k; j++) {
                    noGrassG[j] = true;
                }
            }
        }
        if (cows[i] == 1 && !noGrassH[i]) {
            if (i+k >= n) {
                if (grass[n-1] == 0) {
                    grass[n-1] = 11;
                } else {
                    grass[n-2] = 11;
                }
                for (int j=i; j<n; j++) {
                    noGrassH[j] = true;
                }
            } else {
                grass[i+k] = 11;
                for (int j=i; j<=i+2*k; j++) {
                    noGrassH[j] = true;
                }
            }
        }
    }
    
    int ans = 0;
    for (int i=0; i<n; i++) {
        if (grass[i] == 10 || grass[i] == 11) {
            ans ++;
        }
    }
    cout << ans << endl;
    
    for (int i=0; i<n; i++) {
        if (grass[i] == 0) {
            cout << ".";
        } else if (grass[i] == 10) {
            cout << "G";
        } else if (grass[i] == 11) {
            cout << "H";
        }
    }
    cout << endl;
}

int main() {
    int t;
    cin >> t;
    for (int i=0; i<t; i++) {
        process();
    }
}

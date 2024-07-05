
#include <iostream>
#include <vector>
#include <algorithm>

#define int long long

using namespace std;

char cows[500005];
vector<int> singles;

signed main() {
    int n;
    cin >> n;

    for (int i=0; i<n; i++) {
        cin >> cows[i];
    }

    for (int i=0; i<n; i++) {
        if (cows[i] != cows[i-1] || cows[i] != cows[i+1]) {
            singles.push_back(i);
        }
    }

    int ans=0;

    for (int i : singles) {
        int a=0;
        int b=0;
        for (int j=1; i+j<n; j++) {
            if (cows[i+j] != cows[i]) {
                a++;
            } else if (cows[i+j] == cows[i]){
                break;
            }
        }
        for (int j=1; i-j>=0; j++) {
            if (cows[i-j] != cows[i]) {
                b++;
            } else if (cows[i-j] == cows[i]){
                break;
            }
        }
        //cout << a << endl << b << endl;
        int maxa = 0;
        if (a-1>0) {
            maxa = a-1;
        }
        int maxb = 0;
        if (b-1>0) {
            maxb = b-1;
        }
        
        ans = ans + a*b + maxa + maxb;
    }

    cout << ans;
}


#include <iostream>
#include <algorithm>

#define int long long

using namespace std;

int cows[100005];

signed main() {
    int n;
    cin >> n;
    for (int i=0; i<n; i++) {
        cin >> cows[i];
    }
    sort(cows, cows+n);
    
    int tuition=0;
    int total=0;
    for (int i=0; i<n; i++) {
        int num=n-i;
        if (num * cows[i] > total) {
            total = num * cows[i];
            tuition = cows[i];
            
        }
    }
    
    cout << total << " " << tuition;
}

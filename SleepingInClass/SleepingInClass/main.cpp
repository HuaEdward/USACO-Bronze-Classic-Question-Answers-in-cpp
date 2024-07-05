#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int times[100005];
vector<int> divisors;

int main() {
    int t;
    cin >> t;
    for (int i=0; i<t; i++) {
        int n;
        cin >> n;
        for (int j=0; j<n; j++) {
            cin >> times[j];
        }
        
        // Get divisors
        int sum=0;
        for (int j=0; j<n; j++) {
            sum = sum + times[j];
        }
        
        int max = *max_element(times, times + n);
        if (max == 0) {
            cout << 0 << endl;
            continue;
        }
        
        divisors.clear();
        for (int j=max; j<=sum; j++) {
            if (sum % j == 0) {
                divisors.push_back(j);
            }
        }
        
        // Ckeck if each divisor is valid or not
        int ans = 0;
        for (int j : divisors) {
            int origin=0;
            bool check = true;
            for (int num=0; num < n; num++) {
                origin = origin + times[num];
                if (origin == j) {
                    check = true;
                    origin = 0;
                } else if (origin > j) {
                    check = false;
                    break;
                }
            }
            
            if (check == true) {
                ans = n - sum / j;
                break;
            }
        }
        
        cout << ans << endl;
    }
}

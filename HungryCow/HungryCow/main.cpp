#include <iostream>
#define int long long

using namespace std;

int d[100005];
int b[100005];


signed main() {
    int n, t;
    cin >> n >> t;

    for (int i=0; i<n; i++) {
        cin >> d[i] >> b[i];
    }

    int ans=0;
    int total=b[0];

    for (int i=1; i<n; i++) {
        int eat = min(total, d[i]-d[i-1]);
        ans += eat;
        total -= eat;
        total += b[i];
    }

    ans += min(t-d[n-1]+1, total);
    
    cout << ans;
}

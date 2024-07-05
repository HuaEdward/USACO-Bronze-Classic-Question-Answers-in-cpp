#include <iostream>

using namespace std;

void baseIO(string s) {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  freopen((s + ".in").c_str(), "r", stdin);
  freopen((s + ".out").c_str(), "w", stdout);
}

struct road {
    string type;
    int minT;
    int maxT;
};

road traffic[105];

int main() {
    baseIO("traffic");
    
    int n;
    cin >> n;
    for (int i=0; i<n; i++) {
        cin >> traffic[i].type >> traffic[i].minT >> traffic[i].maxT;
    }
    
    bool on1 = false;
    int minBefore = 0;
    int maxBefore = 1001;
    for (int i=n-1; i>=0; i--) {
        if (traffic[i].type == "none") {
            on1 = true;
        }
        if (on1) {
            if (traffic[i].type == "none") {
                minBefore = max(minBefore, traffic[i].minT);
                maxBefore = min(maxBefore, traffic[i].maxT);
            }
            if (traffic[i].type == "on") {
                minBefore -= traffic[i].maxT;
                maxBefore -= traffic[i].minT;
            }
            if (traffic[i].type == "off") {
                minBefore += traffic[i].minT;
                maxBefore += traffic[i].maxT;
            }
        }
    }
    
    if (minBefore < 0) {
        minBefore = 0;
    }
    if (maxBefore < 0) {
        maxBefore = 0;
    }
    
    cout << minBefore << " " << maxBefore << endl;
    
    bool on2 = false;
    int minAfter = 0;
    int maxAfter = 1001;
    for (int i=0; i<n; i++) {
        if (traffic[i].type == "none") {
            on2 = true;
        }
        if (on2) {
            if (traffic[i].type == "none") {
                minAfter = max(minAfter, traffic[i].minT);
                maxAfter = min(maxAfter, traffic[i].maxT);
            }
            if (traffic[i].type == "on") {
                minAfter += traffic[i].minT;
                maxAfter += traffic[i].maxT;
            }
            if (traffic[i].type == "off") {
                minAfter -= traffic[i].maxT;
                maxAfter -= traffic[i].minT;
            }
        }
    }
    
    if (minAfter < 0) {
        minAfter = 0;
    }
    if (maxAfter < 0) {
        maxAfter = 0;
    }
    
    cout << minAfter << " " << maxAfter;
}

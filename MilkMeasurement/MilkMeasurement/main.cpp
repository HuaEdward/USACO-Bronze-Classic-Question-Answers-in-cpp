#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

struct cow {
    int day;
    string name;
    char change;
    int changeNum;
};

cow cows[105];
int milkM = 7;
int milkE = 7;
int milkB = 7;

bool cmp(const cow& f, const cow& s) {
    return f.day < s.day;
}

void baseIO(string s) {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  freopen((s + ".in").c_str(), "r", stdin);
  freopen((s + ".out").c_str(), "w", stdout);
}

int main() {
    baseIO("measurement");
    int n;
    cin >> n;
    for (int i=0; i<n; i++) {
        cin >> cows[i].day;
        cin >> cows[i].name;
        cin >> cows[i].change;
        cin >> cows[i].changeNum;
    }
    
    sort (cows, cows+n, cmp);
    
    vector<string> top;
    int ans=0;
    
    for (int i=0; i<n; i++) {
        if (cows[i].name == "Mildred") {
            if (cows[i].change == '+') {
                milkM = milkM + cows[i].changeNum;
            }
            if (cows[i].change == '-') {
                milkM = milkM - cows[i].changeNum;
            }
        }
        if (cows[i].name == "Elsie") {
            if (cows[i].change == '+') {
                milkE = milkE + cows[i].changeNum;
            }
            if (cows[i].change == '-') {
                milkE = milkE - cows[i].changeNum;
            }
        }
        if (cows[i].name == "Bessie") {
            if (cows[i].change == '+') {
                milkB = milkB + cows[i].changeNum;
            }
            if (cows[i].change == '-') {
                milkB = milkB - cows[i].changeNum;
            }
        }
        
        int topNum = max(milkB, max(milkE, milkM));
        vector<string> tempTop;
        
        if (topNum == milkB) {
            tempTop.push_back("b");
        }
        if (topNum == milkE) {
            tempTop.push_back("e");
        }
        if (topNum == milkM) {
            tempTop.push_back("m");
        }
        
        bool change = false;
        if (tempTop != top) {
            change = true;
        }
        
        if (change) {
            ans ++;
            top = tempTop;
        }
    }
    
    cout << ans;
}

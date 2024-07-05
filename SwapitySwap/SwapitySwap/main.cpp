#include <iostream>
#include <vector>

using namespace std;

int origin[105];
int change[105];

void reverse(int start, int end) {
    int a = 0;
    while (start + a <= end - a) {
        swap(origin[start + a], origin[end - a]);
        a++;
    }
}

void baseIO(string s) {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  freopen((s + ".in").c_str(), "r", stdin);
  freopen((s + ".out").c_str(), "w", stdout);
}

int main() {
    baseIO("swap");
    int n, k;
    cin >> n >> k;
    int A1, A2, B1, B2;
    cin >> A1 >> A2 >> B1 >> B2;
    
    for (int i = 1; i < n + 1; i++) {
        origin[i] = i;
    }
    
    reverse(A1, A2);
    reverse(B1, B2);
    
    for (int i = 1; i < n + 1; i++) {
        change[origin[i]] = i;
    }
    
    for (int i = 1; i < n + 1; i++) {
        vector<int> process;
        process.push_back(i);
        int now = i;
        do {
            now = change[now];
            process.push_back(now);
        } while (i != now);
        process.pop_back();
        
        int times = k % process.size();
        origin[process[times]] = i;
    }
    
    for (int i = 1; i < n + 1; i++) {
        cout << origin[i] << endl;
    }
}

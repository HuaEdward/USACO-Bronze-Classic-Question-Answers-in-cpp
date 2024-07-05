#include <iostream>
#include <algorithm>

using namespace std;

int limits[105];
int speeds[105];
int answer = 0;

void baseIO(string s) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen((s + ".in").c_str(), "r", stdin);
    freopen((s + ".out").c_str(), "w", stdout);
}

int main() {
    baseIO("speeding");
    int n, m;
    cin >> n >> m;

    int limitIndex = 0;
    for (int i = 0; i < n; i++) {
        int l, s;
        cin >> l >> s;
        for (int j = 0; j < l; j++) {
            limitIndex++;
            limits[limitIndex] = s;
        }
    }

    int speedIndex = 0;
    for (int i = 0; i < m; i++) {
        int l, s;
        cin >> l >> s;
        for (int j = 0; j < l; j++) {
            speedIndex++;
            speeds[speedIndex] = s;
        }
    }

    for (int i = 0; i < 100; i++) {
        answer = max(answer, speeds[i] - limits[i]);
    }

    cout << answer;
}


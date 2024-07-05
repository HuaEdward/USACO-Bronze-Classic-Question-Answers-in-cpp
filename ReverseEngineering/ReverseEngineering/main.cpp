#include <iostream>

using namespace std;

int n, m;
string number[105];
int answer[105];
bool removed[105];

bool check(int i, int j) {
    int zNum = 0;
    int oNum = 0;
    for (int a = 0; a < m; a++) {
        if (removed[a]) {
            continue;
        }
        if (number[a][i] == '0' + j) {
            if (answer[a] == 0) {
                zNum++;
            } else {
                oNum++;
            }
        }
    }
    
    if (zNum == 0 && oNum > 0) {
        return true;
    } else if (oNum == 0 && zNum > 0) {
        return true;
    } else {
        return false;
    }
}

void mark(int i, int j) {
    for (int a = 0; a < m; a++) {
        if (removed[a]) {
            continue;
        }
        if (number[a][i] == '0' + j) {
            removed[a] = true;
        }
    }
}

void process() {
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        removed[i] = false;
        cin >> number[i] >> answer[i];
    }
    
    while (true) {
        bool tag = false;
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < 2; j++) {
                if (check(i, j)) {
                    tag = true;
                    mark(i, j);
                }
            }
        }
        
        if (!tag) {
            break;
        }
    }
    
    int zNum = 0;
    int oNum = 0;
    for (int i = 0; i < m; i++) {
        if (!removed[i]) {
            if (answer[i] == 0) {
                zNum++;
            } else {
                oNum++;
            }
        }
    }
    if (zNum == 0 || oNum == 0) {
        cout << "OK" << endl;
    } else {
        cout << "LIE" << endl;
    }
}

int main() {
    int t;
    cin >> t;
    
    for (int i = 0; i < t; i++) {
        process();
    }
}

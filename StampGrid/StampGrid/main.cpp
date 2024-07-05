
#include <iostream>

using namespace std;

int n = 0;
int k = 0;
char target[21][21];
char stamp[4][21][21];
char canva[21][21];

// 把stamp[index]旋转90度，到stamp[index+1]
void rotation(int index) {
    for (int i = 0; i < k; i++) {
        for (int j = 0; j < k; j++) {
            stamp[index + 1][j][k - i - 1] = stamp[index][i][j];
        }
    }
}

// 只有一种是false：stamp是*，target是.
bool check(int p, int i, int j) {
    for (int a = 0; a < k; a++) {
        for (int b = 0; b < k; b++) {
            if (target[a + i][b + j] == '.' && stamp[p][a][b] == '*') {
                return false;
            }
        }
    }
    return true;
}

// 盖到canva上面
void canvas(int p, int i, int j) {
    for (int a = 0; a < k; a++) {
        for (int b = 0; b < k; b++) {
            if (stamp[p][a][b] == '*') {
                canva[i + a][j + b] = stamp[p][a][b];
            }
        }
    }
}

void paint() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> target[i][j];
        }
    }
    
    cin >> k;
    for (int i = 0; i < k; i++) {
        for (int j = 0; j < k; j++) {
            cin >> stamp[0][i][j];
        }
    }
    
    rotation(0);
    rotation(1);
    rotation(2);
    
    // reset canva
    for (int i = 0; i < 21; i++) {
        for (int j = 0; j < 21; j++) {
            canva[i][j] = '.';
        }
    }
    
    // 1、尝试所有可能的位置
    for (int i = 0; i < n - k + 1; i++) {
        for (int j = 0; j < n - k + 1; j++) {
            // 2、尝试每个stamp
            for (int p = 0; p < 4; p++) {
                // 3、check能不能盖下去
                if (check(p, i, j)) {
                    // 4、能盖下去，就盖下去
                    canvas(p, i, j);
                }
            }
        }
    }
    
    // 5、check canvas和target是否一致
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (target[i][j] != canva[i][j]) {
                cout << "NO" << endl;
                return;
            }
        }
    }
    cout << "YES" << endl;
}

int main() {
    int t = 0;
    cin >> t;
    
    for (int i = 0; i < t; i++) {
        paint();
    }
}

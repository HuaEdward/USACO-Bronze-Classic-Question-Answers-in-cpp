#include <iostream>

using namespace std;

bool better(int a[4], int b[4]) {
    int winCount = 0;
    int loseCount = 0;
    for (int i=0; i<4; i++) {
        for (int j=0; j<4; j++) {
            if (a[i] > b[j]) {
                winCount++;
            }
            if (a[i] < b[j]) {
                loseCount++;
            }
        }
    }
    if (winCount > loseCount) {
        return true;
    } else {
        return false;
    }
}

int main() {
    int t=0;
    cin >> t;
    
    int a[11][4];
    int b[11][4];
    
    for (int i=0; i<t; i++) {
        cin >> a[i][0] >> a[i][1] >> a[i][2] >> a[i][3] >> b[i][0] >> b[i][1] >> b[i][2] >> b[i][3];
        
    }
    
    for (int i=0; i<t; i++) {
        bool check = false;
            for (int c_1=1; c_1<11; c_1++) {
                for (int c_2=1; c_2<11; c_2++) {
                    for (int c_3=1; c_3<11; c_3++) {
                        for (int c_4=1; c_4<11; c_4++) {
                            int c[4] = {c_1, c_2, c_3, c_4};
                            if (better(a[i], b[i]) && better(b[i], c) && better(c, a[i])) {
                                check = true;
                            }
                            if (better(b[i], a[i]) && better(c, b[i]) && better(a[i], c)) {
                                check = true;
                            }
                        }
                    }
                }
            }
        if (check == true) {
            cout << "yes" << endl;
        } else {
            cout << "no" << endl;
        }
    }
}

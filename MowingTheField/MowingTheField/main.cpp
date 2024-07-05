//
//  main.cpp
//  MowingTheField
//
//  Created by Edward Hu on 2024-02-12.
//

#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdio>

using namespace std;

int main() {
    int field[1000][1000] = {0};
    int mowPx = 0;
    int mowPy = 0;
    int n;
    int t = 0;
    char d;
    int s;
    int x = 0;
    
    cin >> n;
    
    for (int i=0; i<n; i++) {
        cin >> d >> s;
        if (d == 'N') {
            for (int a=0; a<s; a++) {
                mowPx ++;
                if (field[mowPx + 100][mowPy + 100] == 0) {
                    field[mowPx + 100][mowPy + 100] = t;
                    t++;
                }
                else {
                    x = min (x, t-field[mowPx][mowPy]);
                }
            }
        }
        
        if (d == 's') {
            for (int a=0; a<s; a++) {
                mowPx --;
                if (field[mowPx + 100][mowPy + 100] == 0) {
                    field[mowPx + 100][mowPy + 100] = t;
                    t++;
                }
                else {
                    x = min (x, t-field[mowPx][mowPy]);
                }
            }
        }
        
        if (d == 'E') {
            for (int a=0; a<s; a++) {
                mowPy ++;
                if (field[mowPx + 100][mowPy + 100] == 0) {
                    field[mowPx + 100][mowPy + 100] = t;
                    t++;
                }
                else {
                    x = min (x, t-field[mowPx][mowPy]);
                }
            }
        }
        
        if (d == 'W') {
            for (int a=0; a<s; a++) {
                mowPy --;
                if (field[mowPx + 100][mowPy + 100] == 0) {
                    field[mowPx + 100][mowPy + 100] = t;
                    t++;
                }
                else {
                    x = min (x, t-field[mowPx][mowPy]);
                }
            }
        }
    }
    
    cout << x;
    
}

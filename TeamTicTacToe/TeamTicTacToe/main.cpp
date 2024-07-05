//
//  main.cpp
//  TeamTicTacToe
//
//  Created by Edward Hu on 2024-02-08.
//

#include <iostream>
#include <algorithm>
#include <cstdio>

using namespace std;

int main() {
    
    freopen("tttt.in", "r", stdin);
    
    char game[3][3];
    int winByOne = 0;
    int winByTwo = 0;
    
    for (int i=0; i<3; i++) {
        for (int n=0; n<3; n++) {
            cin >> game[i][n];
        }
    }
    
    for (int i=0; i<3; i++) {
        if (game[i][0] == game[i][1] || game[i][1] == game[i][2] || game[i][2] == game[i][0]) {
            if (game[i][0] == game[i][1] == game[i][2]) {
                winByOne ++;
            }
            else {
                winByTwo ++;
            }
        }
    }
    
    for (int i=0; i<3; i++) {
        if (game[0][i] == game[1][i] || game[1][i] == game[2][i] || game[2][i] == game[0][i]) {
            if (game[0][i] == game[1][i] == game[2][i]) {
                winByOne ++;
            }
            else {
                winByTwo ++;
            }
        }
    }
    
    int a = game[0][0];
    int b = game[1][1];
    int c = game[2][2];
    int d = game[0][2];
    int e = game[2][0];
    
    if (a == b || b == c || c == a) {
        if (a == b ==c) {
            winByOne ++;
        }
        else {
            winByTwo ++;
        }
    }
    
    if (b == d || d == e || e == b) {
        if (b == d == e) {
            winByOne ++;
        }
        else {
            winByTwo ++;
        }
    }
    
    freopen("tttt.out", "w", stdout);
    
    cout << winByOne << endl << winByTwo;
}

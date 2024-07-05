//
//  main.cpp
//  The Caw-Signal
//
//  Created by Edward Hu on 2024-04-09.
//

#include <iostream>

using namespace std;

void baseIO(string s) {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  freopen((s + ".in").c_str(), "r", stdin);
  freopen((s + ".out").c_str(), "w", stdout);
}

string Signal[11];

string doubleSignal[21];

int main() {
    baseIO("cowsignal");
    
    int M, N, K;
    cin >> M >> N >> K;
    for (int i=0; i<M; i++) {
        cin >> Signal[i];
    }
    
    for (int i=0; i<M; i++) {
        for (int n=0; n<K; n++) {
            for (int j=0; j<N; j++) {
                for (int c=0; c<K; c++) {
                    cout << Signal[i][j];
                }
            }
            cout << endl;
        }
    }
}

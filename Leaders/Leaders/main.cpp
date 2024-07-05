//
//  main.cpp
//  Leaders
//
//  Created by Edward Hu on 2024-04-17.
//

#include <iostream>

using namespace std;

string cows;
int isLeader[100005];
int e[100005];


int main() {
    int n;
    cin >> n;
    cin >> cows;
    for (int i=0; i<n; i++) {
        cin >> e[i];
    }
    
    int gNum=0;
    int hNum=0;
    for (int i=0; i<n; i++) {
        if (cows[i] == 'G') {
            gNum++;
        }
        if (cows[i] == 'H') {
            hNum++;
        }
    }
    
    long firstG = cows.find('G');
    long firstH = cows.find('H');
    long lastG = cows.rfind('G');
    long lastH = cows.rfind('H');
    
    if (e[firstG] >= lastG) {
        isLeader[firstG] = 2;
    }
    if (e[firstH] >= lastH) {
        isLeader[firstH] = 1;
    }
    
    /*for (int i=0; i<n; i++) {
        int gCount=0;
        int hCount=0;
        for (int j=i+1; j<=e[i]; j++) {
            if (cows[j-1] == 'G') {
                gCount++;
            }
            if (cows[j-1] == 'H') {
                hCount++;
            }
        }
        if (cows[i]=='H' && hCount==hNum) {
            isLeader[i] = 1;
        }
        if (cows[i]=='G' && gCount==gNum) {
            isLeader[i] = 2;
        }
    }*/
    
    if (firstG == 0) {
        for (int i=0; i<firstH; i++) {
            if (isLeader[firstH] == 1 && e[i]-1 >= firstH) {
                isLeader[i] = 2;
            }
        }
    }
    
    if (firstH == 0) {
        for (int i=0; i<firstG; i++) {
            if (isLeader[firstG] == 2 && e[i]-1 >= firstG) {
                isLeader[i] = 1;
            }
        }
    }
    
    /*for (int i=0; i<n; i++) {
        for (int j=i+1; j<=e[i]; j++) {
            if (cows[i]=='H' && isLeader[j-1]==2) {
                isLeader[i]=1;
            }
            if (cows[i]=='G' && isLeader[j-1]==1) {
                isLeader[i]=2;
            }
        }
    }*/
    
    int gLeader=0;
    int hLeader=0;
    for (int i=0; i<n; i++) {
        if (isLeader[i] == 1) {
            hLeader++;
        }
        if (isLeader[i] == 2) {
            gLeader++;
        }
    }
    
    cout << gLeader*hLeader;
}

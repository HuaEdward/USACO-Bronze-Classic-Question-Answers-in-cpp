//
//  main.cpp
//  DaisyChains
//
//  Created by Edward Hu on 2024-03-25.
//

#include <iostream>
using namespace std;

int flowers[105];
int answer;

int main(){
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> flowers[i];
    }
    
    for (int i = 0; i < n; i++) {
        for  (int j = i; j < n; j++) {
            int total = 0;
            double average = 0.0;
            for (int t = i; t <= j; t++) {
                total += flowers[t];
            }
            average = (total + 0.0) / (j-i+1.0);
            for (int t = i; t <= j; t++) {
                if (flowers[t]==average) {
                    answer++;
                    break;
                }
            }
        }
    }
    
    cout << answer;
}

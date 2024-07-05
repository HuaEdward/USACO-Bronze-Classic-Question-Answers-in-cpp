//
//  main.cpp
//  MajorityOpinion
//
//  Created by Edward Hu on 2024-04-12.
//

#include <iostream>
#include <set>

using namespace std;

int opinions[11][100005];
int opinionLength[11];

int t;

int main() {
    cin >> t;
    for (int i=0; i<t; i++) {
        cin >> opinionLength[i];
        for (int j=0; j<opinionLength[i]; j++) {
            cin >> opinions[i][j];
        }
    }
    
    for (int i=0; i<t; i++) {
        set<int> ans;
        for (int j=0; j<opinionLength[i]-1; j++) {
            if (opinions[i][j] == opinions [i][j+1]) {
                ans.insert(opinions[i][j]);
            } else if (opinions[i][j] == opinions [i][j+2] && opinions[i][j] != opinions [i][j+1]) {
                ans.insert(opinions[i][j]);
            }
        }
        if (ans.empty()) {
            ans.insert(-1);
        }
        
        int s = ans.size();
        if (s > 1) {
            for (int a=1; a<s; a++) {
                cout << ans.count(a) << " ";
            }
            cout << ans.count(s);
        } else {
            cout << ans.count(1);
        }
        cout << "\n";
    }
}

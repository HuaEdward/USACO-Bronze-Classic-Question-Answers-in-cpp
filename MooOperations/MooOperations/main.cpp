//
//  main.cpp
//  MooOperations
//
//  Created by Edward Hu on 2024-04-11.
//

#include <iostream>

using namespace std;
string strs[105];

int main() {
    int q;
    cin >> q;
    for(int i=0; i<q; i++) {
        cin >> strs[i];
    }
    
    for (int i=0; i<q; i++) {
        if (strs[i].find("MOO") >= 0 && strs[i].find("MOO") != 18446744073709551615) {
            cout << strs[i].length() - 3 << endl;
            continue;
        } else if (strs[i].find("MOM") >= 0 && strs[i].find("MOM") != 18446744073709551615) {
                cout << strs[i].length() - 2 << endl;
                continue;
        } else if (strs[i].find("OOO") >= 0 && strs[i].find("OOO") != 18446744073709551615) {
            cout << strs[i].length() - 2 << endl;
            continue;
        } else if (strs[i].find("OOM") >= 0 && strs[i].find("OOM") != 18446744073709551615) {
            cout << strs[i].length() - 1 << endl;
            continue;
        } else {
            cout << -1 << endl;
            continue;
        }
    }
}

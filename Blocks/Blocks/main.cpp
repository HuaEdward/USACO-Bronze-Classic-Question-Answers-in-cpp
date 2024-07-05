#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int n;
char cubes[4][6];
string words[11];
bool spell[11];
vector<char> selected;

bool compare(string s, vector<char> v){
    sort(v.begin(), v.end());
    do {
        if (s == string(v.begin(), v.end())) {
            return true;
        }
    }while(next_permutation(v.begin(), v.end()));
    return false;
}

void recursion(int i){
    if (i == 4) {
        for (int j=0; j<n; j++) {
            if (compare(words[j], selected)) {
                spell[j] = true;
            }
        }
        return;
    }
    
    recursion(i+1);
    
    selected.push_back(cubes[i][0]);
    recursion(i+1);
    selected.pop_back();
    
    selected.push_back(cubes[i][1]);
    recursion(i+1);
    selected.pop_back();
    
    selected.push_back(cubes[i][2]);
    recursion(i+1);
    selected.pop_back();
    
    selected.push_back(cubes[i][3]);
    recursion(i+1);
    selected.pop_back();
    
    selected.push_back(cubes[i][4]);
    recursion(i+1);
    selected.pop_back();
    
    selected.push_back(cubes[i][5]);
    recursion(i+1);
    selected.pop_back();
}

int main() {
    cin >> n;
    for(int i=0; i<4; i++) {
        for (int j=0; j<6; j++) {
            cin >> cubes[i][j];
        }
    }
    
    for (int i=0; i<n; i++) {
        cin >> words[i];
    }
    
    recursion(0);
    
    for (int i=0; i<n; i++) {
        if (spell[i]) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
}

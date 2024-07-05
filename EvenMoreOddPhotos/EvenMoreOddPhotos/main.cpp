#include <iostream>

using namespace std;

int O;
int E;
int ans;

int main() {
    int n;
    cin >> n;
    for (int i=0; i<n; i++) {
        int num;
        cin >> num;
        if (num % 2 == 0) {
            E++;
        } else {
            O++;
        }
    }
    
    if (E == O || E == O+1) {
        ans = E + O;
    }
    if (E > O+1) {
        ans = 2*O + 1;
    }
    if (E < O) {
        if ((O-E)%3 == 0){
            ans = 2*E + (O-E)/3*2;
        }
        if ((O-E)%3 == 1){
            ans = 2*E + (O-E)/3*2 - 1;
        }
        if ((O-E)%3 == 2){
            ans = 2*E + (O-E)/3*2 + 1;
        }
    }
    
    cout << ans;
}

#include <iostream>
#include <algorithm>

#define int long long

using namespace std;

int numbers[7];

signed main() {
    for (int i=0; i<7; i++) {
        cin >> numbers[i];
    }
    sort(numbers, numbers+7);
    
    int a = numbers[0];
    int b = numbers[1];
    int c = numbers[2];
    for (int i=2; i<7; i++) {
        if (c == a + b) {
            c = numbers[i+1];
            continue;
        } else {
            break;
        }
    }
    cout << a << " " << b << " " << c;
}

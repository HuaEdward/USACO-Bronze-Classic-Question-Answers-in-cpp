#include <iostream>

using namespace std;

int originPosition[100005];
int realPosition[100005];
int sortedNum = 1;

int main() {
    int n;
    cin >> n;
    for (int i=0; i<n; i++) {
        cin >> originPosition[i];
    }
    
    for (int i=1; i<n+1; i++) {
        int num;
        cin >> num;
        realPosition[num] = i;
    }
    
    int maxNum = realPosition[originPosition[0]];
    for (int i=0; i<n-1; i++) {
        if (maxNum < realPosition[originPosition[i+1]]) {
            maxNum = realPosition[originPosition[i+1]];
            sortedNum ++;
        }
    }
    
    cout << n - sortedNum;
}

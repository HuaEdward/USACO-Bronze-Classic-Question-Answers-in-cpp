#include <algorithm>
#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

vector<int> ms;

int main() {
    int n;
    cin >> n;
    
    string str;
    cin >> str;
    
    int day = 10000000;
    for (int i = 0; i < n; ++i) {
        // 如果是i，代表开始
        if (str[i] == '1') {
            int j = i + 1;
            while (j < n && str[j] == '1') {
                j++;
            }
            // 说明【i，j-1】全部是1
            double m = j - i;
            // m存起来
            ms.push_back(m);
            
            // 是不是边界
            int max;
            if (i == 0 || j == n) {
                max = m-1;
            }
            // 不是边界
            else {
                max = (m-1)/2;
            }
            day = min(day, max);
            
            // 跳过连续1区间
            i = j;
        }
    }
    
    int ans = 0;
    for (double num : ms) {
        ans += ceil(num/(2*day+1));
    }
    
    cout << ans;
}

//
//  main.cpp
//  TheBucketList
//
//  Created by Edward Hu on 2024-02-07.
//

#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>

using namespace std;

int startTime[1001];
int finishTime[1001];
int buckets[100];
int totalBuckets[100];
int bucketAmount = 0;
int ans = 0;

int main() {
    freopen("blist.in", "r", stdin);
    
    int n;
    cin >> n;
    for (int i=0; i<n; i++) {
        int s, t, b;
        cin >> s >> t >> b;
        
        startTime[s] = finishTime[t] = b;
        /*cin >> startTime[i];
        cin >> finishTime[i];
        cin >> buckets[i];*/
    }
    
    for (int i=0; i<1001; i++) {
        bucketAmount += startTime[i] - finishTime[i];
        ans = max(ans, bucketAmount);
    }
    
    freopen("blist.out", "w", stdout);
    cout << ans;
}

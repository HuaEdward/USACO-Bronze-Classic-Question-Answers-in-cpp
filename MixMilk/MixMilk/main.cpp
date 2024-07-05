#include <algorithm>
#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;

void pour (int& c1, int& m1, int& c2, int& m2)
{
    int amt = min(c2 - m2, c1);
    m1 = m1 - amt;
    m2 = m2 + amt;
}

int main()
{
    freopen("mixmilk.in", "r", stdin);
    
    vector<int> capacity(3);
    vector<int> amount(3);

    for (int i=0; i<3; i++)
    {
        cin >> capacity[i];
        cin >> amount[i];
    }
    
    for (int i=0; i<33; i++)
    {
        pour(capacity[0], amount[0], capacity[1], amount[1]);
        pour(capacity[1], amount[1], capacity[2], amount[2]);
        pour(capacity[2], amount[2], capacity[0], amount[0]);
    }
    pour(capacity[0], amount[0], capacity[1], amount[1]);
    
    freopen("mixmilk.out", "w", stdout);
    for (int a : amount)
    {
        cout << a << endl;
    }
}


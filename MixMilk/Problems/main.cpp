//
//  main.cpp
//  Problems
//
//  Created by Edward Hu on 2024-02-04.
//

//
//  18BrDecP1.cpp
//  USACO-Bronze-preparation
//
//  Created by Edward Hu on 2024-02-04.
//

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
    
    /*for (int i=0; i<3; i++)
    {
        int b = i+1;
        cout << "enter the capacity of bucket" + to_string(b) + ": "<< endl;
        int a;
        cin >> a;
        capacity.push_back(a);
    }
    
    for (int q=0; q<3; q++)
    {
        int b = q+1;
        cout << "enter the amount of bucket" + to_string(b) + " (amount < capactiy): "<< endl;
        int c;
        cin >> c;
        amount.push_back(c);
    }*/
    for (int i=0; i<3; i++)
    {
        //scanf("%d %d", &capacity[i], &amount[i]);
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


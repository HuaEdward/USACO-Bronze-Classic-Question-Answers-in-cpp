#include <iostream>
#include <vector>

using namespace std;

struct cow{
    int s, t, c;
};

struct conditioner{
    int a, b, p, m;
};

int N, M;
cow cows[21];
conditioner conditioners[11];
int stalls[100];
int changedStalls[100];
vector<int> selected;
int ans = 100000;

// 面对第idx个元素，选还是不选
// 参数：第idx个元素
void subset(int idx) {
    // 终止条件
    if (idx == M) {
        // 输出结果
        for (int i=0; i<100; i++) {
            changedStalls[i] = stalls[i];
        }
        
        int totalCost = 0;
        for (auto i : selected) {
            for (int j=conditioners[i].a; j<=conditioners[i].b; j++) {
                changedStalls[j] -= conditioners[i].p;
            }
            totalCost += conditioners[i].m;
        }
        
        bool ok = true;
        for (int i=0; i<100; i++) {
            if (changedStalls[i] > 0) {
                ok = false;
                break;
            }
        }
        
        if (ok) {
            ans = min(ans, totalCost);
        }
        
        return;
    }
    
    // 选择一：不选
    subset(idx + 1);
    
    // 选择二：选
    selected.push_back(idx);
    subset(idx + 1);
    
    // 还原现场（递归之前做了什么，递归之后要还原回去）
    selected.pop_back();
}

int main() {
    cin >> N >> M;
    for (int i=0; i<N; i++) {
        cin >> cows[i].s >> cows[i].t >> cows[i].c;
    }
    for (int i=0; i<M; i++) {
        cin >> conditioners[i].a >> conditioners[i].b >> conditioners[i].p >> conditioners[i].m;
    }
    for (int i=0; i<N; i++) {
        for (int j=cows[i].s; j<=cows[i].t; j++) {
            stalls[j] = cows[i].c;
        }
    }
    
    subset(0);
    
    cout << ans;
}

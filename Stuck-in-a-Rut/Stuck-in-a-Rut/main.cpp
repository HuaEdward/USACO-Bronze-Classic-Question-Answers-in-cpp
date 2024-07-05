#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct east{
    int x;
    int y;
    int idx;
    bool stop;
    int eat;
};

struct north{
    int x;
    int y;
    int idx;
    bool stop;
    int eat;
};

bool east_cmp(const east& f, const east& s) {
    return f.y < s.y;
}

bool north_cmp(const north& f, const north& s) {
    return f.x < s.x;
}

bool east_final_cmp(const east& f, const east& s) {
    return f.idx < s.idx;
}

bool north_final_cmp(const north& f, const north& s) {
    return f.idx < s.idx;
}

vector<east> es;
vector<north> ns;

int main() {
    int n;
    cin >> n;
    for (int i=0; i<n; i++) {
        char c;
        cin >> c;
        if (c == 'E') {
            int a, b;
            cin >> a >> b;
            es.push_back({a, b, i, false, 0});
        } else {
            int a, b;
            cin >> a >> b;
            ns.push_back({a, b, i, false, 0});
        }
    }
    
    sort(es.begin(), es.end(), east_cmp);
    sort(ns.begin(), ns.end(), north_cmp);
    
    for (int i=0; i<es.size(); i++) {
        for (int j=0; j<ns.size(); j++) {
            if (ns[j].x > es[i].x && ns[j].y < es[i].y && ns[j].stop == false) {
                if (ns[j].x - es[i].x == es[i].y - ns[j].y) {
                    continue;
                }
                if (ns[j].x - es[i].x < es[i].y - ns[j].y) {
                    ns[j].stop = true;
                    ns[j].eat = es[i].y - ns[j].y;
                }
                if (ns[j].x - es[i].x > es[i].y - ns[j].y) {
                    es[i].stop = true;
                    es[i].eat = ns[j].x - es[i].x;
                    break;
                }
            }
        }
    }
    
    sort(es.begin(), es.end(), east_final_cmp);
    sort(ns.begin(), ns.end(), north_final_cmp);
    
    for (int i=0; i<n; i++) {
        bool fd = false;
        for (int a=0; a<es.size(); a++) {
            if (es[a].idx == i) {
                if (!es[a].stop && es[a].eat == 0) {
                    cout << "Infinity" << endl;
                } else {
                    cout << es[a].eat << endl;
                }
                fd = true;
                break;
            }
        }
        if (!fd) {
            for (int a=0; a<ns.size(); a++) {
                if (ns[a].idx == i) {
                    if (!ns[a].stop && ns[a].eat == 0) {
                        cout << "Infinity" << endl;
                    } else {
                        cout << ns[a].eat << endl;
                    }
                    break;
                }
            }
        }
    }
}

#include <iostream>
using namespace std;

string words[105][2];

int CharNum(string str, char c) {
  int charNum = 0;
  for (char i : str) {
    if (i == c) {
      charNum++;
    }
  }
  return charNum;
}

void baseIO(string s) {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  freopen((s + ".in").c_str(), "r", stdin);
  freopen((s + ".out").c_str(), "w", stdout);
}

int main() {
  baseIO("blocks");
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> words[i][0] >> words[i][1];
  }

  for (char l = 'a'; l <= 'z'; l++) {
    int num = 0;
    // 逐行计算，需要多少个l
    for (int i = 0; i < n; i++) {
      num += max(CharNum(words[i][0], l), CharNum(words[i][1], l));
    }
    // 比较两个string，计算需要多少个l，取较大值
    cout << num << endl;
  }
}

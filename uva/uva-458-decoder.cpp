#include <iostream>

using namespace std;

int main() {
  string s;
  while (cin >> s) {
    for (int i = 0; i < s.size(); i++) {
      char c;
      if ((s[i] - 7) < 32)
        c = 127 - (33 - (s[i] - 7));
      else
        c = s[i] - 7;
      cout << c;
    }
    cout << endl;
  }
  return 0;
}

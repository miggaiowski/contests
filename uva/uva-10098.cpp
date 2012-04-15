#include <iostream>
#include <algorithm>
#include <string.h>

using namespace std;

int main() {

  int n;
  char s[10];
  cin >> n;
  while (n--) {
    cin >> s;
    int size = strlen(s);
    sort(s, s+size);
    do {
      cout << s << endl;
    } while (next_permutation(s, s+size));
    cout << endl;
  }

  return 0;
}

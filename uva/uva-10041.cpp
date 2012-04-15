#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
#include <sstream>
#include <cmath>

using namespace std;

int main() {

  int ncases;
  int r;
  int houses[30001];
scanf("%d", &ncases);

  while (ncases--) {
    cin >> r;
    int mi = 0x3f3f3f3f, ma = 0, total = 0;
    for (int i = 0; i < r; i++) {
      cin >> houses[i];
      mi = min(houses[i], mi);
      ma = max(houses[i], ma);
      total += houses[i];
    }
    double med = (double)total / (double)(ma-mi);
    if (med - (int)med > 0.5)
      med = (int)med + 1;
    else
      med = (int)med;
    total = 0;
    for (int i = 0; i < r; i++) {
      total += abs(houses[i] - med);
    }
    cout << total << endl;
  }
  return 0;
}

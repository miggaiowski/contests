#include <iostream>
#include <algorithm>
#include <limits.h>
#include <cmath>
#include <cstdio>

using namespace std;

int n;
double x[101];
double y[101];

double d(int i, int j) {
  return sqrt((x[i]-x[j])*(x[i]-x[j]) + (y[i]-y[j])*(y[i]-y[j]));
}

double prim() {
  double menor = INT_MAX, ret = 0;
  double dist[101];
  int done[101], m;
  for (int i = 0; i < n; i++) {
    dist[i] = d(0, i);
    done[i] = 0;
  }
  done[0] = 1;
  int nv = 1;
  while (nv < n) {
    menor = INT_MAX;
    for (int i = 0; i < n; i++) {
      if (!done[i] && dist[i] < menor) {
        menor = dist[i];
        m = i;
      }
    }
    done[m] = 1;
    for (int i = 0; i < n; i++) {
      if (!done[i]) {
        dist[i] = min(dist[i], d(m, i));
      }
    }
    ret += menor;
    nv++;
  }
  return ret;
}

int main() {
  int t, first = 1;;
  cin >> t;
  while (t--) {
    cin >> n;
    for (int i = 0; i < n; i++) {
      cin >> x[i] >> y[i];
    }
    if (!first)
      cout << endl;
    else
      first = 0;
    printf("%.2lf\n", prim());
  }

  return 0;
}

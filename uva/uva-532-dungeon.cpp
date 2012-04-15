#include <iostream>
#include <cstdio>
#include <queue>
#include <string.h>

using namespace std;

char dun[32][32][32];
int v[32][32][32];

struct tri {
  int i, j, k, t;
  tri(int i = -1, int j = -1, int k = -1, int t = 0) : i(i), j(j), k(k), t(t) {};
};

void print(int l, int r, int c) {
  for (int i = 0; i <= l+1; i++) {
    for (int j = 0; j <= r+1; j++) {
      for (int k = 0; k <= c+1; k++) {
        cout << dun[i][j][k];
      }
      cout << endl;
    }
    cout << endl;
  }
}

int main() {
  
  int l, r, c;
  cin >> l >> r >> c;
  while (l && r && c) {
    tri start;
    memset(dun, '#', sizeof(dun));
    memset(v, 0, sizeof(v));
    for (int i = 1; i <= l; i++) {
      for (int j = 1; j <= r; j++) {
        for (int k = 1; k <= c; k++) {
          scanf(" %c", &dun[i][j][k]);
          if (dun[i][j][k] == 'S') {
            start.i = i;
            start.j = j;
            start.k = k;
          }
        }
      }
    }

    int ok, x, y, z;
    tri curr, next;
    start.t = 0;
    queue <tri> q;
    q.push(start);
    v[curr.i][curr.j][curr.k] = 1;
    while (!q.empty()) {
      ok = 0;
      curr = q.front(); q.pop(); curr.t += 1;
      next = curr; next.i = curr.i - 1; 
      x = next.i; y = next.j; z = next.k;
      if (dun[x][y][z] == 'E') { ok=curr.t; break;}
      else if(dun[x][y][z] == '.' && !v[x][y][z]) { q.push(next); v[x][y][z] = 1; }
      next = curr; next.i = curr.i + 1;
      x = next.i; y = next.j; z = next.k;
      if (dun[x][y][z] == 'E') { ok=curr.t; break;}
      else if(dun[x][y][z] == '.' && !v[x][y][z]) { q.push(next); v[x][y][z] = 1; }
      next = curr; next.j = curr.j - 1;
      x = next.i; y = next.j; z = next.k;
      if (dun[x][y][z] == 'E') { ok=curr.t; break;}
      else if(dun[x][y][z] == '.' && !v[x][y][z]) { q.push(next); v[x][y][z] = 1; }
      next = curr; next.j = curr.j + 1;
      x = next.i; y = next.j; z = next.k;
      if (dun[x][y][z] == 'E') { ok=curr.t; break;}
      else if(dun[x][y][z] == '.' && !v[x][y][z]) { q.push(next); v[x][y][z] = 1; }
      next = curr; next.k = curr.k - 1;
      x = next.i; y = next.j; z = next.k;
      if (dun[x][y][z] == 'E') { ok=curr.t; break;}
      else if(dun[x][y][z] == '.' && !v[x][y][z]) { q.push(next); v[x][y][z] = 1; }
      next = curr; next.k = curr.k + 1;
      x = next.i; y = next.j; z = next.k;
      if (dun[x][y][z] == 'E') { ok=curr.t; break;}
      else if(dun[x][y][z] == '.' && !v[x][y][z]) { q.push(next); v[x][y][z] = 1; }
    }
    
    if (ok) { 
      cout << "Escaped in " << ok << " minute(s)." << endl;
    }
    else {
      cout << "Trapped!" << endl;
    }

    cin >> l >> r >> c;
  }
  return 0;
}

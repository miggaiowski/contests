#include <iostream>
#include <string.h>

using namespace std;

int adj[200][200];
int nadj[200];
char color[200];

int bip(int u, char c) {
  if (!color[u]) {
    color[u] = c;
    for (int i = 0; i < nadj[u]; i++) {
      if (!bip(adj[u][i], (c==1) ? 2 : 1))
        return 0;
    }
    return 1;
  }
  else if (color[u] == c)
    return 1;
  return 0;
}

int main() {

  int n, m, u, v;
  cin >> n;
  while (n) {
    memset(adj, 0, sizeof(adj));
    memset(nadj, 0, sizeof(nadj));
    memset(color, 0, sizeof(color));
    cin >> m;
    while (m--) {
      cin >> u >> v;
      adj[u][nadj[u]++] = v;
      adj[v][nadj[v]++] = u;
    }
    if (bip(0, 1)) {
      cout << "BICOLORABLE." << endl;
    }
    else {
      cout << "NOT BICOLORABLE." << endl;
    }

    cin >> n;
  }

  return 0;
}

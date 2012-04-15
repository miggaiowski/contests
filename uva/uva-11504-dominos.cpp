#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <set>

using namespace std;

#define MAXN 100123

int *indeg;
int *visited;

int comp[MAXN], vis[MAXN], high[MAXN];
int num, ncomp;
vector <int> stck;

void dfscc(vector <vector <int> > &adj, int u) {
  unsigned int i;
  int v;
  high[u] = vis[u] = num--;
  stck.push_back(u);
  for (i = 0; i < adj[u].size(); i++) {
    v = adj[u][i];
    if (!vis[v]) {
      dfscc(adj, v);
      high[u] = max(high[u], high[v]);
    } else if (vis[v] > vis[u] && !comp[v])
      high[u] = max(high[u], vis[v]);
  }
  if (high[u] == vis[u]) {
    ncomp++;
    do {
      v = stck.back(); stck.pop_back();
      comp[v] = ncomp;
    } while (v != u);
  }
}

void scc(vector < vector <int> > &adj, int n) {
  int i;
  ncomp = 0; num = n;
  stck.clear();
  memset(vis, 0, sizeof(vis));
  memset(comp, 0, sizeof(comp));
  for (i = 0; i < n; i++)
    if (!vis[i])
      dfscc(adj, i);
}



int main() {
  int n, m, t, u, v;
  cin >> t;
  while (t--) {
    cin >> n >> m;
 
    vector < vector <int> > adj(n);

    for (int i = 0; i < m; i++) {
      cin >> u >> v;
      u--; v--; // vertices comecam em 1
      adj[u].push_back(v);
    }

    scc(adj, n);

    vector <int> indeg(ncomp, 0);
    for (int u = 0; u < n; u++) {
      for (int j = 0; j < adj[u].size(); j++) {
        int v = adj[u][j];
        if (comp[u] != comp[v]) {
          indeg[comp[v]-1]++;
        }
      }
    }
    int total = 0;
    for (int i = 0; i < ncomp; i++) {
      if (!indeg[i]) {
        total++;        
      }
    }
    cout << total << endl;
  }

  return 0;
}

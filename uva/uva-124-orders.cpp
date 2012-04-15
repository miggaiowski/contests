#include <iostream>
#include <sstream>
#include <vector>
#include <string.h>
#include <algorithm>

using namespace std;


vector<char> nome;

int adj[30][30];

int good(string s) {
  for (int i = s.size()-1; i > 0; i--) {
    for (int j = i-1; j >= 0; j--) {
      if (adj[s[i]-'a'][s[j]-'a']) {
        return 0;
      }
    }
  }
  return 1;
}

int main() {
  string vars, cons, cvars;
  char a, b;
  int first = 1;
  while (getline(cin, vars)) {
    if (!first) cout << endl; else first = 0;
    nome.clear();
    stringstream ss(vars);

    cvars = "";
    while (ss >> a) {
      nome.push_back(a);
      cvars += a;
    }

    memset(adj, 0, sizeof(adj));
    getline(cin, cons);
    stringstream ss2(cons);
    while (ss2 >> a >> b) {
      adj[(char)a - 'a'][(char)b - 'a'] = 1;
    }

    sort(cvars.begin(), cvars.end());
    do {
      if (good(cvars))
        cout << cvars << endl;
    } while ( next_permutation(cvars.begin(), cvars.end()));

  }
  return 0;
}

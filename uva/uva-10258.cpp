#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
#include <sstream>

using namespace std;

typedef struct {
  int team;
  int nsolved;
  int penal[10];
  int right[10];
  int penalty;
  bool used;
} co;

bool cmp_co (co a, co b) {
  if (a.nsolved > b.nsolved)
    return true;
  else if (a.nsolved < b.nsolved)
    return false;
  else {
    if (a.penalty < b.penalty)
      return true;
    else if (a.penalty > b.penalty)
      return false;
    else {
      if (a.team < b.team)
	return true;
      else
	return false;
    }
  }
}

int main() {

  vector < co > player (101);

  for (int i = 0; i < 101; i++) {
    for (int j = 0; j < 10; j++) {
      player[i].penal[j] = 0;
      player[i].right[j] = 0x3f3f3f3f;
    }
    player[i].team = i;
    player[i].nsolved = 0;
    player[i].penalty = 0;
    player[i].used = false;
  }
  string str;
  int n, p, tempo, prob;
  char car;
  scanf("%d", &n);
  
  getline(cin, str);
  getline(cin, str);
  while (n--) {
    for (int i = 0; i < 101; i++) {
      for (int j = 0; j < 10; j++) {
	player[i].penal[j] = 0;
	player[i].right[j] = 0x3f3f3f3f;
      }
      player[i].team = i;
      player[i].nsolved = 0;
      player[i].penalty = 0;
      player[i].used = false;
    }
    while (getline(cin, str) && str.length() > 0) {
      stringstream ss(str);
      ss >> p >> prob >> tempo >> car;

      player[p].used = true;

      if ( car == 'C' ) {
	player[p].right[prob] = min(player[p].right[prob], tempo);
      }
      else if ( car == 'I') {
	if (player[p].right[prob] == 0x3f3f3f3f)
	  player[p].penal[prob] += 1;
      }
    }
    for (int i = 0; i < 101; i++) {
      for (int j = 0; j < 10; j++) {
	if (player[i].right[j] != 0x3f3f3f3f) {
	  player[i].nsolved += 1;
	  player[i].penalty += player[i].right[j] + 20*player[i].penal[j];
	}
      }
    }
    sort(player.begin(), player.end(), cmp_co);
    for (int i = 0; i < 101; i++) {
      if (player[i].used == true) {
	cout << player[i].team << " " << player[i].nsolved << " " << player[i].penalty << endl;
      }
    }
    if (n)
      cout << endl;
  }
  return 0;
}

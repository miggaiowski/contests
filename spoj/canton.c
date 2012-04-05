#include <stdio.h>

int main(){

  int i, j;

  int n,t,m;

  scanf("%d", &t);

  while (t) {
    t--;
    i = j = 1;
    scanf("%d", &n);
    m = n;
    while (m > 1) {
      if (i == 1 && j % 2) {
	j++;
	m--;
	
	while (m>1 && j != 1) {
	  j--; i++; m--;
	}
      }
      else if (j == 1 && !(i % 2)) {
	i++; m--;
	
	while (m>1 && i != 1) {
	  j++; i--; m--;
	}
      }
    }

    printf("TERM %d IS %d/%d\n", n, i, j);
  }

  return 0;
}

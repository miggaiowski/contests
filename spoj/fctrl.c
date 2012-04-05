/* 2007-08-27  */

#include <stdio.h>

int main(){
  int t;
  int n, nzeros=0, a;
  
  scanf("%d", &t);
  while(t){
    t--;
    scanf("%d", &n);
    a=n/5;
    nzeros=a;
    while(a){
      a/=5;
      nzeros+=a;
    }
    printf("%d\n", nzeros);
  }
  return 0;
}


/* 2008-07-01 */

#include <stdio.h>
#include <string.h>

int main(){

  int n, m, c, i;
  int size, fim;
/*   int coelhos1, coelhos2, coelhos3; */

  int fibo[1123123];

  scanf("%d", &c);
  while (c) {
    c--;
    
    /*     coelhos1 = 0; */
    /*     coelhos3 = coelhos2 = 1; */
    
    fibo[0] = 0;
    fibo[1] = fibo[2] = 1;

    scanf("%d %d", &n, &m);
    
    size = 1 << m;
    
    fim = n % (3 * (1 << (m - 1)));
    
    for (i = 2; i <= fim + 1; i++) {
      /* 	coelhos1 = coelhos2; */
      /* 	coelhos2 = coelhos3; */
      /* 	coelhos3 = (coelhos2 + coelhos1) % size; */
      
      fibo[i] = (fibo[i-1]+fibo[i-2]) >= size ? 
	(fibo[i-1]+fibo[i-2]) % size :
	(fibo[i-1]+fibo[i-2]);
    }
    
/*     printf("%d\n", coelhos3);     */
    printf("%d\n", fibo[fim + 1]);    

  }
  
  return 0;
}

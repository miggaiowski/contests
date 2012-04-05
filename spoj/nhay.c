/* 2007-08-30 */

#include <stdio.h>
#include <string.h>
#include <malloc.h>

int* pi;
int np;

void cpf(char* p){
  int m, k, q;
  
  m=np;
  pi[1]=0;
  k=0;
  
  for(q=2; q<=m; q++){
    while(k>0 && p[k+1]!=p[q]){
      k=pi[k];
    }
    if(p[k+1]==p[q]){
      k++;
    }
    pi[q]=k;
  }
/*   for(q=1; q<=m; q++){ */
/*     printf("%d ", pi[q]); */
/*   } */
/*   printf("\n"); */
  return;
}
  
void kmp(char* p){
  int i, m, q;
  char t='a';

  m=np;
  cpf(p);
  q=0;

  for(i=1;; i++){
    scanf("%c", &t);
    if(t=='\n'){
      printf("\n");
      return;
    }
    while(q>0 && p[q+1]!=t){
      q=pi[q];
    }
    if(p[q+1]==t){
      q++;
    }
    if(q==m){
      printf("%d\n", i-m);
      q=pi[q];
    }
  }
  return;
}




int main(){
  
  char* p;

  while(scanf("%d", &np)==1){
    p=(char*)malloc(sizeof(char)*np+1);
    pi=(int*)malloc(sizeof(int)*np+1);
    scanf("%s", p+1);
    getchar();
    //    printf("%s\n", p+sizeof(char));
    kmp(p);
  }
  

  
  return 0;
}

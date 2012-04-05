/* 2009-05-16 */

#include <stdio.h>

int max(int a, int b) {
  return a > b ? a : b;
}

int main() {

  int n, W, i, j, sumfees;
  int A[111][511], C[111][511];
  int w[111], p[111];

  while (scanf("%d %d", &W, &n) && n && W) {
    for (i = 1; i <= n; i++) {
      scanf("%d %d", &w[i], &p[i]);
    }
    for (i = 0; i <= n; i++) {
      A[i][0] = 0;
      C[i][0] = 0;
    }
    for (i = 0; i <= W; i++) {
      A[0][i] = 0;
      C[0][i] = 0;
    }
    for (i = 1; i <= n; i++) {
      for (j = 1; j <= W; j++) {
	if (w[i] > j) {
	  A[i][j] = A[i-1][j];
	  C[i][j] = C[i-1][j];
	}
	else {
	  if (max(w[i] + C[i-1][j-w[i]], C[i-1][j]) > j) {
	    A[i][j] = A[i-1][j];
	    C[i][j] = C[i-1][j];
	  }
	  else {
	    if ( (p[i] + A[i-1][j-w[i]]) >= A[i-1][j]) {
	      A[i][j] = p[i] + A[i-1][j-w[i]];
	      C[i][j] = w[i] + C[i-1][j-w[i]];
	    }
	    else {
	      A[i][j] = A[i-1][j];
	      C[i][j] = C[i-1][j];
	    }
	  }
	}
      } 
    }

    sumfees = C[n][W];
    for (i = 0; i < W; i++) {
      if (A[n][i] == A[n][W] && C[n][i] < sumfees) {
	sumfees = C[n][i];
      }
    }

    printf("%d %d\n", sumfees, A[n][W]);

/*     printf("    "); */
/*     for (i = 0; i <= W; i++) { */
/*       printf("%02d ", i); */
/*     } */
/*     printf("\n\n"); */
/*     for (i = 0; i <= n; i++) { */
/*       printf("%02d  ", i); */
/*       for (j = 0; j<= W; j++) { */
/* 	printf("%02d ", A[i][j]); */
/*       } */
/*       printf("\n"); */
/*     } */

/*     printf("\n    "); */
/*     for (i = 0; i <= W; i++) { */
/*       printf("%02d ", i); */
/*     } */
/*     printf("\n\n"); */
/*     for (i = 0; i <= n; i++) { */
/*       printf("%02d  ", i); */
/*       for (j = 0; j<= W; j++) { */
/* 	printf("%02d ", C[i][j]); */
/*       } */
/*       printf("\n"); */
/*     } */


  }

  return 0;
}

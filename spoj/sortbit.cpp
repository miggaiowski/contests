// 2012-03-31 

#include <iostream>
#include <string.h>

using namespace std;

int pascal[33][33];
// pascal[i][j] é igual a combinação de i, j a j. == i!/j!(i-j)!

void preenchePascal() {
  memset(pascal, 0, sizeof(pascal));
  pascal[0][0] = 1;
  for (int i = 1; i <= 32; i++) {
    pascal[i][0] = 1;
    for (int j = 1; j <= i; j++) {
      pascal[i][j] = pascal[i-1][j] + pascal[i-1][j-1];
    }
  }
}

// retorna quantos números <= x têm exatamente k bits setados.
// para cada bit 1 em x, temos todos os espaços a direita deste bit
// para colocar k bits 1 e ainda ser menos, ou seja, para cada bit 1 encontrado,
// varrendo do mais significativo para o menos, temos que somar pascal[i][k]
// numeros que são menores e tem k bits.
int menores_que_x_com_k_bits(int x, int k) {
  int original_k = k; // guarda o k original para usar depois
  int bits1 = 0; // numero de bits 1 em x
  int total = 0;
  for (int i = 31; i >= 0; i--) {
    if (x & (1 << i)) { // se tem o i-ésimo bit ligado
      bits1++;
      if (k >= 0) { // só conta se tivermos bits para permutar
        total += pascal[i][k]; // desligando o bit i, temos i posicoes para colocar k bits
        k--; // assume que o i-ésimo bit está ligado, sobra um bit a menos para permutar
      }
    }
  }
  // contamos quantos são menores, mas pode ser que o próprio x tenha k bits,
  // e neste caso temos que somar um ao total.
  if (bits1 == original_k)
    total++;
  return total;  
}

// acha quantos bits tem o k-esimo e salva em *nbits, retorna
// a posição do k-ésimo depois do primeiro com nbits.
int posicao_e_bits_no_kesimo(int m, int n, int k, int *nbits) {
  // numeros com i bits entre n e m = menores que n - menores que m
  // contamos quantos numeros entre m e n temos em cada classe
  // somando tudo, até que chegue ao k-ésimo, quando isto acontecer
  // teremos encontrado a classe dele
  int total = 0, last_total = 0;
  int i = 0;
  while (total < k) { // enquanto não tivermos contado k numeros
    i++; // proximo numero de bits 
    last_total = total; 
    total += menores_que_x_com_k_bits(n, i)  // soma numeros de i bits
      - menores_que_x_com_k_bits(m-1, i); // m-1 para não descontar o próprio m.
  }
  *nbits = i;
  return k - last_total;
}

// faz busca binaria no intervalo [m,n] procurando uma posição 
// até a qual temos k numeros de nbits. O que estiver nesta
// posicao é o k-ésimo, retornamos ele.
int binSearch(int m, int n, int k, int nbits) {
  int a = m, b = n, mid, q;
  while (a < b) {
    mid = a + (b-a)/2; // == (a+b)/2 so que sem overflow.
    q = menores_que_x_com_k_bits(mid, nbits) - menores_que_x_com_k_bits(m-1, nbits);
    if (q < k) 
      a = mid+1;
    else
      b = mid;
  }
  return a;
}

int main() {
  preenchePascal();
  int t, m, n, k, nbits;
  cin >> t;
  while (t--) {
    cin >> m >> n >> k;  
    if (m >=0 && n >= 0) { // positivos
      if (n == 0 || k == 0) {
        cout << 0 << endl;
      }
      else {
        if (m == 0) { // triangulo de pascal quebraria
          m = 1; // joga o intervalo para frente
          k--; // e pega o (k-1)-ésimo
        }
        int p = posicao_e_bits_no_kesimo(m, n, k, &nbits);
        int res = binSearch(m, n, p, nbits);
        // cerr << p << " " << nbits << endl;
        cout << res << endl;
      }
    }
    else {
      if (n == 0) {
        n--; // joga intervalo para 'frente'
        k--; // e pega o (k-1)-ésimo
      }
      if (k == 0)
        cout << 0 << endl;
      else {
        m = m & (~(1<<31)); // ignora bit de sinal
        n = n & (~(1<<31));
        int p = posicao_e_bits_no_kesimo(m, n, k, &nbits);
        int res = (1<<31) | binSearch(m, n, p, nbits); // coloca o bit de sinal 
        // cerr << p << " " << nbits << endl;
        cout << res << endl;
      }
    }
  }
  return 0;
}

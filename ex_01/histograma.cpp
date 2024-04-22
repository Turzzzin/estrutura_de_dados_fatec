#include <iostream>
#include <string>
using namespace std;

int main() {
  float nAlunos, notas[100];
  string a, b, c, d, e;
  cout << "Insira o n. de Alunos: ";
  cin >> nAlunos;
  for (int i = 0; i < nAlunos; i++) {
    cout << "Insira a nota " << i + 1 << ": ";
    cin >> notas[i];
    if (notas[i] >= 9) {
      a = a + "*";
    } else if (notas[i] >= 7 && notas[i] < 9) {
      b = b + "*";
    } else if (notas[i] >= 5 && notas[i] < 7) {
      c = c + "*";
    } else if (notas[i] >= 3 && notas[i] < 5) {
      d = d + "*";
    } else if (notas[i] < 3) {
      e = e + "*";
    }
  }
  cout << "A: " << a << endl;
  cout << "B: " << b << endl;
  cout << "C: " << c << endl;
  cout << "D: " << d << endl;
  cout << "E: " << e << endl;
}
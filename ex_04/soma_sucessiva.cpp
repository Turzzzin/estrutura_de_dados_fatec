#include <iostream>
using namespace std;

int multiplicacaoRecursiva(int a, int b){
    if(b == 0){
        return 0;
    } else {
        return a + multiplicacaoRecursiva(a, b - 1);
    }
}

int main(){
    int a, b;

    cout << "Insira o valor de a e de b: ";
    cin >> a >> b;

    int resultado = multiplicacaoRecursiva(a, b);

    cout << "Resultado da multiplicacao: " << resultado << endl;

    return 0;
}
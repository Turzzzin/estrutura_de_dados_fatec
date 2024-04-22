#include <iostream>
using namespace std;

class EquacaoSegundoGrau {
private:
    double a;
    double b;
    double c;
    double delta;

public:
    EquacaoSegundoGrau(double coeficienteA, double coeficienteB, double coeficienteC) {
        a = coeficienteA;
        b = coeficienteB;
        c = coeficienteC;
        calcularDelta();
    }

    void calcularDelta() {
        delta = b * b - 4 * a * c;
    }

    double getDelta() {
        return delta;
    }

};

int main() {
    double coeficienteA, coeficienteB, coeficienteC;
    cout << "Digite os coeficientes 'a', 'b' e 'c': ";
    cin >> coeficienteA >> coeficienteB >> coeficienteC;

    EquacaoSegundoGrau equacao(coeficienteA, coeficienteB, coeficienteC);
    double delta = equacao.getDelta();
    
    cout << "Delta: " << delta << endl;

    return 0;
}
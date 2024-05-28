#include <iostream>
#include <queue>
using namespace std;

class Fila {
    private:
        queue<char> itens;

    public:
        Fila() {}

        bool esta_vazia() const {
            return itens.empty();
        }

        void enqueue(char valor) {
            itens.push(valor);
        }

        char dequeue() {
            if (esta_vazia()) {
                cout << "Fila vazia." << endl;
                return '\0'; // Valor de erro, idealmente deveria lançar uma exceção
            } else {
                char valor = itens.front();
                itens.pop();
                return valor;
            }
        }
};

int main() {
    Fila fila_maiusculas;
    Fila fila_minusculas;
    char valor;

    cout << "Digite caracteres (pressione ENTER para finalizar):" << endl;
    
    while (true) {
        valor = cin.get();
        if (valor == '\n') {
            break;
        }
        if (isupper(valor)) {
            fila_maiusculas.enqueue(valor);
        } else if (islower(valor)) {
            fila_minusculas.enqueue(valor);
        }
    }

    cout << "Desenfileirando valores da fila de maiúsculas:" << endl;
    while (!fila_maiusculas.esta_vazia()) {
        cout << fila_maiusculas.dequeue() << " ";
    }
    cout << endl;

    cout << "Desenfileirando valores da fila de minúsculas:" << endl;
    while (!fila_minusculas.esta_vazia()) {
        cout << fila_minusculas.dequeue() << " ";
    }
    cout << endl;

    return 0;
}

#include <iostream>
using namespace std;

class Pilha {
    private:
        int topo;
        int tam_max;
        int *itens;

    public:
        Pilha(int n) : tam_max(n), topo(-1) {
            itens = new int[tam_max];
        }

        ~Pilha() {
            delete[] itens;
        }

        bool esta_cheia() const {
            return topo >= tam_max - 1;
        }

        bool esta_vazia() const {
            return topo == -1;
        }

        void push(int valor) {
            if (esta_cheia()) {
                cout << "Pilha cheia." << endl;
            } else {
                itens[++topo] = valor;
            }
        }

        int pop() {
            if (esta_vazia()) {
                cout << "Pilha vazia." << endl;
                return -1; // Valor de erro, idealmente deveria lançar uma exceção
            } else {
                return itens[topo--];
            }
        }

        int top() const {
            if (esta_vazia()) {
                cout << "Pilha vazia." << endl;
                return -1; // Valor de erro, idealmente deveria lançar uma exceção
            } else {
                return itens[topo];
            }
        }

        int tamanho() const {
            return topo + 1;
        }
};

int main() {
    Pilha pilha_pares(10);
    Pilha pilha_impares(10);
    int valor;

    cout << "Digite 10 valores inteiros:" << endl;

    for (int i = 0; i < 10; ++i) {
        cin >> valor;
        if (valor % 2 == 0) {
            pilha_pares.push(valor);
        } else {
            pilha_impares.push(valor);
        }
    }

    cout << "Desempilhando valores da pilha de pares:" << endl;
    while (!pilha_pares.esta_vazia()) {
        cout << pilha_pares.pop() << " ";
    }
    cout << endl;

    cout << "Desempilhando valores da pilha de ímpares:" << endl;
    while (!pilha_impares.esta_vazia()) {
        cout << pilha_impares.pop() << " ";
    }
    cout << endl;

    return 0;
}

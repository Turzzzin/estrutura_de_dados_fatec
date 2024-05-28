#include <iostream>
using namespace std;

class Pilha {
    private:
        int topo;
        int tam_max;
        double *itens;

    public:
        Pilha(int n) : tam_max(n), topo(-1) {
            itens = new double[tam_max];
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

        void push(double valor) {
            if (esta_cheia()) {
                cout << "Pilha cheia." << endl;
            } else {
                itens[++topo] = valor;
            }
        }

        void pop() {
            if (esta_vazia()) {
                cout << "Pilha vazia." << endl;
            } else {
                topo--;
            }
        }

        double top() const {
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
    int capacidade;
    cout << "Digite a capacidade máxima da pilha: ";
    cin >> capacidade;

    Pilha pilha(capacidade);
    int item_menu;
    double valor;

    cout << "PROGRAMA PILHA" << endl;
    cout << "0: Sair" << endl;
    cout << "1: Inserir itens" << endl;
    cout << "2: Remover itens" << endl;
    cout << "3: Imprimir Tamanho" << endl;
    cout << "4: Imprimir Item Topo" << endl;

    do {
        cout << "Entre com a opcao desejada: ";
        cin >> item_menu;

        switch (item_menu) {
        case 0:
            cout << "Saindo..." << endl;
            break;
        case 1:
            cout << "Digite o valor para inserir: ";
            cin >> valor;
            pilha.push(valor);
            break;
        case 2:
            pilha.pop();
            break;
        case 3:
            cout << "Tamanho da pilha: " << pilha.tamanho() << endl;
            break;
        case 4:
            cout << "Item no topo da pilha: " << pilha.top() << endl;
            break;
        default:
            cout << "Opcao invalida. Tente novamente." << endl;
            break;
        }
    } while (item_menu != 0);

    return 0;
}

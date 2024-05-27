#include <iostream>
using namespace std;

class Pilha(int n) {
    private:
        int topo;
        int tam_max;
        double *itens;
    public:
        Pilha() : tamanho(0) {}

    bool esta_cheia() const {
        return tamanho >= capacidade_maxima;
    }

    void pop(float valor) {
        if(esta_cheia()){
            cout << "Pilha cheia."
        } else {
            elementos[tamanho] = valor;
            tamanho++;
        }
    }
};

int main(){
    Pilha pilha;
    int item_menu;

    cout << "PROGRAMA PILHA" << endl;
    cout << "0: Sair" << endl;
    cout << "1: Inserir itens" << endl;
    cout << "2: Remover itens" << endl;
    cout << "3: Imprimir Tamanho" << endl;
    cout << "4: Imprimir Item Topo" << endl;
    cout << "Entre com a opçao desejada: ";
    cin >> item_menu;
    do {
        switch (item_menu) {
        case 0:
            return 0;
        case 1:
            pilha.pop()
            break;
        }
    } while (item_menu != 0);

    return 0;
}
# Estrutura de dados
### **Profa.** Divani Barbosa Gavinier
### Trabalho 02
### **Aluno:** Artur Fagundes Guimarães
***
# Exercícios:
01) Faça o seguinte menu interativo com o usuário para a chamada das funções de um programa que simule uma pilha de floats:
* 0: Sair
* 1: Inserir itens
* 2: Remover itens
* 3: Imprimir tamanho
* 4: Imprimir item do topo
Entre com a opcao desejada:

Importante:
Caso 1: Inserir itens: Verificação antes da chamada da função se o tamanho da pilha é menor que o tamanho máximo ajustado ao vetor

Caso 2 e 4: Remover e imprimir item: Verificação antes da chamada da função se a pilha está vazia.
```c++
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

```
***
02) Construa um programa que leia 10 valores do tipo int e empilha-os conforme forem pares ou impares na pilha 1 e pilha 2, Respectivamente. No final desempilhe os valores de cada pilha
```c++
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

```
***
03) Desenvolva um programa em C que leia n caracteres digitados pelo usuário, até que o mesmo pressione a tecla ENTER, e os atribua a uma fila conforme forem letras maiúsculas e minúsculas, fila 1 e fila 2, respectivamente. No final retire o conteúdo de cada fila mostrando-os na tela.
```c++
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

```
***
04) Desenvolva um programa em C++ que leia do usuário 10 caracteres de uma lista simplesmente encadeada e os imprima na tela juntamente com:
a) O endereço de cada elemento da lista.
b) O endereço do ponteiro de próximo.
```c++

```
***
05) Desenvolva um programa em C que adiciona 20 itens no programa "Lista Duplamente Encadeada com Funções" desenvolvido em sala de aula. Use valores inteiros iniciados com 1 em ordem crescente. Adicione nesse programa uma chamada para função que seja responsável por realizar a busca binária de itens nessa lista. Implemente essa função
```c++

```
***
06) Desenhe uma arvore binária usando a seguinte sequência de dados de entrada: 14, 4, 15, 3, 9, 13, 18, 7, 11, 16, 20, 5, 17, 4 e 5
a) Responda: Quantas folhas, nós e qual a altura da árvore?
b) Escreva a árvore em pré-ordem e pós-ordem
c) Desenhe as árvores depois da inserção do nó 21 e da remoção do nó 18
```arvore-binaria
          14
        /    \
      4      15
     / \        \
    3   9      18
       / \    /   \
      7  13  16   20
     /   /     \
    5  11       17

```
a) 
* Folhas (Nós sem filhos): 3, 5, 11, 17 e 20 (5 Folhas)
* Nós: 13
* Altura: 4 (níveis de 0 a 3)
b) 
* Pré-ordem: 14, 4, 3, 9, 7, 5, 13, 11, 15, 18, 16, 17, 20
* Pós-ordem: 3, 5, 7, 11, 13, 9, 4, 17, 16, 20, 18, 15, 14
c) 
```inserção nó 21
          14
        /    \
      4      15
     / \        \
    3   9       18
       / \     /   \
      7  13   16    20
     /   /         /  \
    5  11         17   21
```
```remoção do nó 18
          14
        /    \
      4      15
     / \        \
    3   9       20
       / \     /   \
      7  13   16   21
     /   /         /
    5  11        17

```

***

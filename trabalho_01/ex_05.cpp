#include <iostream>
#include <cstdlib>
#include <ctime>
#include <algorithm>

using namespace std;

int bbr(int v[], int baixo, int alto, int chave){
    int meio;
    while(baixo <= alto) {
        meio = (baixo + alto) / 2;
        if(v[meio] == chave) return meio;
        if(v[meio] < chave) return bbr(v, meio+1, alto, chave);
        else return bbr(v, baixo, meio-1, chave);
    }
    return -1;
}

int main() {
    // Definindo o tamanho do vetor e o limite superior para números aleatórios
    const int tamanhoVetor = 50;
    const int limiteSuperior = 100;

    // Alocando memória para o vetor
    int* vetor = new int[tamanhoVetor];

    // Inicializando o gerador de números aleatórios
    // **srand(time(NULL));** // Removido

    // Preenchendo o vetor com números aleatórios
    for (int i = 0; i < tamanhoVetor; ++i) {
        vetor[i] = rand() % (limiteSuperior + 1);
    }

    // Ordenando o vetor
    sort(vetor, vetor + tamanhoVetor);

    // Imprimindo o conteúdo do vetor na tela
    cout << "Vetor ordenado: ";
    for (int i = 0; i < tamanhoVetor; ++i) {
        cout << vetor[i] << " ";
    }

    cout << endl;
    int chave;

    cout << "Indique o valor que deseja buscar: ";
    cin >> chave;

    int posicao = bbr(vetor, 0, tamanhoVetor - 1, chave);

    cout << "Valor encontrado na posicao: " << posicao << ". " << endl;

    // Liberando memória alocada para o vetor
    delete[] vetor;

    return 0;
}   
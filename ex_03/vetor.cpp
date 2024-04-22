#include <iostream>
using namespace std;

float* popularVetor(int tamanhoVetor, float vetor[]) {
    float valor;
    for (int i = 0; i < tamanhoVetor; i++) {
        cout << "Insira o valor na posicao " << i << ": ";
        cin >> valor;
        vetor[i] = valor;
    }
    return vetor; 
}

float* dobraVetor(int tamanhoVetor, float vetor[]) {
    for(int i = 0; i < tamanhoVetor; i++) {
        vetor[i] = vetor[i] * 2;
    }
    return vetor;
}

int main(void) {
    int tamanhoVetor;
    float vetor[100]; // Declare the array with a static size (optional)

    cout << "Digite o tamanho do vetor: ";
    cin >> tamanhoVetor;

    float* vetorPopulado = popularVetor(tamanhoVetor, vetor); // Receive the reference to the populated array

    // Access and print elements using the returned reference
    cout << "Valores do vetor: ";
    for (int i = 0; i < tamanhoVetor; i++) {
        cout << vetorPopulado[i] << " ";
    }
    cout << endl;

    float* vetorDobrado = dobraVetor(tamanhoVetor, vetor);

    cout << "Valores dobrados: ";
        for (int i = 0; i < tamanhoVetor; i++) {
        cout << vetorDobrado[i] << " ";
    }
    cout << endl;

    return 0;
}

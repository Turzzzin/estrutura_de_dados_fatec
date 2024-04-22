# Estrutura de dados
### **Profa.** Divani Barbosa Gavinier
### Trabalho 01
### **Aluno:** Artur Fagundes Guimarães
***
# Exercícios:
1) 
```c++
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
```
***
2)
```c++
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
```
***
3)
```c++
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
```
***
4)
```c++
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
```
***
5)
```c++
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
```
***
6)
```c++
#include <iostream>
#include <vector>
#include <time.h>

using namespace std;

// Função para gerar um vetor aleatório de números inteiros
vector<int> gerarVetorAleatorio(int tamanho)
{
  vector<int> vetor(tamanho);

  for (int i = 0; i < tamanho; i++)
  {
    vetor[i] = rand() % 1000000;
  }

  return vetor;
}

// Função para ordenar um vetor usando o algoritmo Bubble Sort
void bubbleSort(vector<int> &vetor)
{
  for (int i = 0; i < vetor.size() - 1; i++)
  {
    for (int j = 0; j < vetor.size() - i - 1; j++)
    {
      if (vetor[j] > vetor[j + 1])
      {
        swap(vetor[j], vetor[j + 1]);
      }
    }
  }
}

// Função para ordenar um vetor usando o algoritmo Selection Sort
void selectionSort(vector<int> &vetor)
{
  for (int i = 0; i < vetor.size() - 1; i++)
  {
    int menorIndice = i;

    for (int j = i + 1; j < vetor.size(); j++)
    {
      if (vetor[j] < vetor[menorIndice])
      {
        menorIndice = j;
      }
    }

    swap(vetor[i], vetor[menorIndice]);
  }
}

// Função para ordenar um vetor usando o algoritmo Quick Sort
void quickSort(vector<int> &vetor, int inicio, int fim)
{
  if (inicio < fim)
  {
    int pivo = vetor[fim];
    int i = inicio - 1;

    for (int j = inicio; j < fim; j++)
    {
      if (vetor[j] <= pivo)
      {
        i++;
        swap(vetor[i], vetor[j]);
      }
    }

    swap(vetor[i + 1], vetor[fim]);
    quickSort(vetor, inicio, i);
    quickSort(vetor, i + 2, fim);
  }
}
void quickSortWrapper(vector<int> &vetor)
{
  quickSort(vetor, 0, vetor.size() - 1); // Assuming bubbleSort takes start and end indices
}
// Função para ordenar um vetor usando o algoritmo Merge Sort
void mergeSort(vector<int> &vetor, int inicio, int fim)
{
  if (inicio < fim)
  {
    int meio = (inicio + fim) / 2;

    mergeSort(vetor, inicio, meio);
    mergeSort(vetor, meio + 1, fim);

    vector<int> vetorTemp(fim - inicio + 1);

    int i = inicio, j = meio + 1, k = 0;

    while (i <= meio && j <= fim)
    {
      if (vetor[i] <= vetor[j])
      {
        vetorTemp[k++] = vetor[i++];
      }
      else
      {
        vetorTemp[k++] = vetor[j++];
      }
    }

    while (i <= meio)
    {
      vetorTemp[k++] = vetor[i++];
    }

    while (j <= fim)
    {
      vetorTemp[k++] = vetor[j++];
    }

    for (int i = inicio; i <= fim; i++)
    {
      vetor[i] = vetorTemp[i - inicio];
    }
  }
}

void mergeSortWrapper(vector<int> &vetor)
{
  mergeSort(vetor, 0, vetor.size() - 1); // Assuming bubbleSort takes start and end indices
}

// Função para medir o tempo de execução de um algoritmo de ordenação
double medirTempoOrdenacao(vector<int> &vetor, void (*funcaoOrdenacao)(vector<int> &))
{
  clock_t inicio, fim;

  // Faz uma cópia do vetor desordenado
  vector<int> vetorDesordenado = vetor;

  inicio = clock();

  // Chama a função de ordenação
  funcaoOrdenacao(vetor);

  fim = clock();

  // Calcula o tempo gasto em milisegundos
  double tempoGasto = (double)(fim - inicio) / (double)CLOCKS_PER_SEC * 1000;

  return tempoGasto;
}

int main()
{
  // Variáveis para armazenar os tempos de ordenação
  double tempoBubbleSort, tempoSelecao, tempoInsercao, tempoQuickSort, tempoMergeSort;

  // Variável para armazenar a quantidade de elementos
  int quantidadeElementos;

  // Solicita ao usuário a quantidade de elementos
  cout << "Entre com a quantidade de elementos que deseja ordenar: ";
  cin >> quantidadeElementos;

  // Gera um vetor aleatório com a quantidade de elementos especificada
  vector<int> vetor = gerarVetorAleatorio(quantidadeElementos);

  // Mede o tempo de ordenação para cada algoritmo
  tempoBubbleSort = medirTempoOrdenacao(vetor, bubbleSort);
  tempoSelecao = medirTempoOrdenacao(vetor, selectionSort);
  tempoQuickSort = medirTempoOrdenacao(vetor, quickSortWrapper);
  tempoMergeSort = medirTempoOrdenacao(vetor, mergeSortWrapper);

  // Exibe os resultados na tela
  cout << "\nTempo Gasto BubbleSort: " << tempoBubbleSort << " milisegundos" << endl;
  cout << "Tempo Gasto Selecao: " << tempoSelecao << " milisegundos" << endl;
  cout << "Tempo Gasto Insercao: " << tempoInsercao << " milisegundos" << endl;
  cout << "Tempo Gasto QuickSort: " << tempoQuickSort << " milisegundos" << endl;
  cout << "Tempo Gasto MergeSort: " << tempoMergeSort << " milisegundos" << endl;

  return 0;
}
```
***
7)
```c++
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

struct Funcionario {
    string nome;
    int idade;
    char sexo;
    int tempo_de_casa;
    float salario;
    int departamento;
};

int main() {
    const int num_departamentos = 8;
    vector<Funcionario> funcionarios;

    // Adicionando funcionarios ficticios para exemplo
    funcionarios.push_back({"Joao", 30, 'M', 5, 5000.0, 1});
    funcionarios.push_back({"Maria", 28, 'F', 3, 4500.0, 2});
    funcionarios.push_back({"Pedro", 35, 'M', 7, 6000.0, 3});
    funcionarios.push_back({"Ana", 33, 'F', 8, 5500.0, 4});
    funcionarios.push_back({"Carlos", 32, 'M', 6, 5200.0, 5});
    funcionarios.push_back({"Juliana", 29, 'F', 4, 4700.0, 6});
    funcionarios.push_back({"Marcos", 34, 'M', 9, 6200.0, 7});
    funcionarios.push_back({"Luciana", 31, 'F', 2, 4800.0, 8});
    // a) Procurar no cadastro e informar todos os dados do funcionario com nome informado pelo usuario
    string nome_procurado;
    cout << "Digite o nome do funcionario a ser procurado: ";
    cin >> nome_procurado;
    bool encontrado = false;
    for (const auto& funcionario : funcionarios) {
        if (funcionario.nome == nome_procurado) {
            encontrado = true;
            cout << "Dados do funcionario encontrado:" << endl;
            cout << "Nome: " << funcionario.nome << endl;
            cout << "Idade: " << funcionario.idade << endl;
            cout << "Sexo: " << funcionario.sexo << endl;
            cout << "Tempo de casa: " << funcionario.tempo_de_casa << " anos" << endl;
            cout << "Salario: R$" << funcionario.salario << endl;
            cout << "Departamento: " << funcionario.departamento << endl;
            break;
        }
    }
    if (!encontrado) {
        cout << "Funcionario não encontrado." << endl;
    }
    
    // b) Informar o numero de funcionarios de determinado departamento
    int departamento_procurado;
    cout << "Digite o numero do departamento para contar os funcionarios: ";
    cin >> departamento_procurado;
    int num_funcionarios_departamento = count_if(funcionarios.begin(), funcionarios.end(), 
        [departamento_procurado](const Funcionario& f) { return f.departamento == departamento_procurado; });
    cout << "Numero de funcionarios no departamento " << departamento_procurado << ": " << num_funcionarios_departamento << endl;
    
    // c) O numero de funcionarios do sexo feminino
    int num_funcionarios_feminino = count_if(funcionarios.begin(), funcionarios.end(), 
        [](const Funcionario& f) { return f.sexo == 'F'; });
    cout << "Numero de funcionarios do sexo feminino: " << num_funcionarios_feminino << endl;
    
    // d) Exibir os dados dos funcionarios com menor e com maior tempo de casa
    auto menor_tempo_de_casa = min_element(funcionarios.begin(), funcionarios.end(), 
        [](const Funcionario& a, const Funcionario& b) { return a.tempo_de_casa < b.tempo_de_casa; });
    auto maior_tempo_de_casa = max_element(funcionarios.begin(), funcionarios.end(), 
        [](const Funcionario& a, const Funcionario& b) { return a.tempo_de_casa < b.tempo_de_casa; });
    cout << "Funcionario com menor tempo de casa:" << endl;
    cout << "Nome: " << menor_tempo_de_casa->nome << ", Tempo de casa: " << menor_tempo_de_casa->tempo_de_casa << " anos" << endl;
    cout << "Funcionario com maior tempo de casa:" << endl;
    cout << "Nome: " << maior_tempo_de_casa->nome << ", Tempo de casa: " << maior_tempo_de_casa->tempo_de_casa << " anos" << endl;
    
    // e) Exibir o salario medio, por departamento
    for (int i = 1; i <= num_departamentos; ++i) {
        float salario_total = 0;
        int num_funcionarios = 0;
        for (const auto& funcionario : funcionarios) {
            if (funcionario.departamento == i) {
                salario_total += funcionario.salario;
                num_funcionarios++;
            }
        }
        if (num_funcionarios != 0) {
            cout << "Salario medio no departamento " << i << ": R$" << salario_total / num_funcionarios << endl;
        } else {
            cout << "Não ha funcionarios no departamento " << i << endl;
        }
    }
    
    // f) Exibir a idade media, por departamento
    for (int i = 1; i <= num_departamentos; ++i) {
        float idade_total = 0;
        int num_funcionarios = 0;
        for (const auto& funcionario : funcionarios) {
            if (funcionario.departamento == i) {
                idade_total += funcionario.idade;
                num_funcionarios++;
            }
        }
        if (num_funcionarios != 0) {
            cout << "Idade media no departamento " << i << ": " << idade_total / num_funcionarios << " anos" << endl;
        } else {
            cout << "Não ha funcionarios no departamento " << i << endl;
        }
    }
    
    // g) Exibir o numero de funcionarios do sexo masculino e feminino, com idade entre 29 e 35 anos
    int num_funcionarios_masculino_29_35 = count_if(funcionarios.begin(), funcionarios.end(), 
        [](const Funcionario& f) { return f.idade >= 29 && f.idade <= 35 && f.sexo == 'M'; });
    int num_funcionarios_feminino_29_35 = count_if(funcionarios.begin(), funcionarios.end(), 
        [](const Funcionario& f) { return f.idade >= 29 && f.idade <= 35 && f.sexo == 'F'; });
    cout << "Numero de funcionarios masculinos entre 29 e 35 anos: " << num_funcionarios_masculino_29_35 << endl;
    cout << "Numero de funcionarios femininos entre 29 e 35 anos: " << num_funcionarios_feminino_29_35 << endl;
    
    return 0;
}
```
***

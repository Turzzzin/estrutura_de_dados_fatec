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
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
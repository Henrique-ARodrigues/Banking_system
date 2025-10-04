#include <iostream>
#include "auxiliary.hpp"
#include "user.hpp"

using namespace std;

//Funções auxiliares para testar o sistema usando a main
//Esse arquivo foi criado pra usar o sistema e as funções
//Mas usando um vetor temporário para testar o funcionamento

void criarConta(vector<BankAccount> &contas, int &proximoNumeroConta) {
    string nome, cpf;
    double saldoInicial;

    cin.ignore();
    cout << "Nome: "; getline(cin, nome);
    cout << "CPF: "; getline(cin, cpf);
    cout << "Saldo inicial: "; cin >> saldoInicial;

    User user(nome, cpf);
    BankAccount novaConta(user, saldoInicial, proximoNumeroConta++);
    contas.push_back(novaConta);

    cout << "Conta criada com sucesso!\n";
}

void depositar(vector<BankAccount> &contas) {
    int numeroConta; double valor;
    cout << "Número da conta: "; cin >> numeroConta;
    cout << "Valor: "; cin >> valor;

    bool achou = false;
    for(auto &conta : contas) {
        if(conta.getNumeroConta() == numeroConta) {
            conta.deposito(valor);
            achou = true;
            break;
        }
    }
    if(!achou) cout << "Conta não encontrada!\n";
}

void sacar(vector<BankAccount> &contas) {
    int numeroConta; double valor;
    cout << "Número da conta: "; cin >> numeroConta;
    cout << "Valor: "; cin >> valor;

    bool achou = false;
    for(auto &conta : contas) {
        if(conta.getNumeroConta() == numeroConta) {
            conta.saque(valor);
            achou = true;
            break;
        }
    }
    if(!achou) cout << "Conta não encontrada!\n";
}

void transferir(vector<BankAccount> &contas) {
    int origem, destino;
    double valor;
    cout << "Conta origem: "; cin >> origem;
    cout << "Conta destino: "; cin >> destino;
    cout << "Valor: "; cin >> valor;

    BankAccount *contaOrigem = nullptr;
    BankAccount *contaDestino = nullptr;

    for(auto &c : contas) {
        if(c.getNumeroConta() == origem) contaOrigem = &c;
        if(c.getNumeroConta() == destino) contaDestino = &c;
    }

    if(contaOrigem && contaDestino) {
        contaOrigem->transferencia(valor, *contaDestino);
    } else {
        cout << "Conta inválida!\n";
    }
}

void transferirParaDuasContas(vector<BankAccount> &contas) {
    int origem, destino1, destino2;
    double valor;

    cout << "Conta origem: "; cin >> origem;
    cout << "Conta destino 1: "; cin >> destino1;
    cout << "Conta destino 2: "; cin >> destino2;
    cout << "Valor total a transferir: "; cin >> valor;

    BankAccount *contaOrigem = nullptr;
    BankAccount *contaDestino1 = nullptr;
    BankAccount *contaDestino2 = nullptr;

    for (auto &conta : contas) {
        if (conta.getNumeroConta() == origem) contaOrigem = &conta;
        if (conta.getNumeroConta() == destino1) contaDestino1 = &conta;
        if (conta.getNumeroConta() == destino2) contaDestino2 = &conta;
    }

    if (contaOrigem && contaDestino1 && contaDestino2) {
        contaOrigem->transferencia(valor, *contaDestino1, *contaDestino2);
        cout << "Transferência concluída!\n";
    } else {
        cout << "Alguma conta inválida!\n";
    }
}

void mostrarExtrato(const vector<BankAccount> &contas) {
    int numeroConta;
    cout << "Número da conta: "; cin >> numeroConta;

    bool achou = false;
    for(const auto &conta : contas) {
        if(conta.getNumeroConta() == numeroConta) {
            conta.exibirExtrato();
            achou = true;
            break;
        }
    }
    if(!achou) cout << "Conta não encontrada!\n";
}

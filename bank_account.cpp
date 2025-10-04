#include <iostream>
#include "bank_account.hpp"
//Incluindo o cabecalho, que ja tem o cabecalho de user tambem
//E a biblioteca da linguagem


//Construtor da Conta usando o construtor de User
BankAccount::BankAccount(const User& user, double saldo_inicial, int numeroConta)
    : conta(numeroConta), saldo(saldo_inicial), titular(user) { 
}


//Faz o deposito na conta do titular
void BankAccount::deposito(double valor) {
    saldo += valor;
    //Salva o extrato depois de qualquer alteracao no saldo
    //Isso vai acontece em todas a funcoes que mexem diretamente no saldo
    //Decidimos implementar essa funcao, achamos que seria interessante
    extrato[extratoIndex] = saldo;
    extratoIndex++;
}

//Faz um saque na conta do titular 
void BankAccount::saque(double valor) {
    //Verifica se existe a possibilidade
    //Isso vai ocorrer em outras funcoes
    if(saldo < valor) {
        std::cout << "Valor insuficiente para saque" << std::endl;
    }
    else {
        saldo -= valor;
        extrato[extratoIndex] = saldo;
        extratoIndex++;
    }
}

//Funcoes sobrecarregadas
void BankAccount::transferencia(double valor, BankAccount &destino) {
    if(saldo < valor) {
        std::cout << "Sem saldo para essa quantia" << std::endl;
    }
    //Faz a transferencia da conta do titular para a conta destino
    else {
        saldo -= valor;
        destino.deposito(valor);
        extrato[extratoIndex] = saldo;
        extratoIndex++;
    }
}

//Faz uma transferencia de metade do valor que o titular tirou da conta dele
//E transfere igualmente para duas contas destino
void BankAccount::transferencia(double valor, BankAccount &destino1, BankAccount &destino2) {
    if(saldo < valor) {
        std::cout << "Sem saldo para essa quantia" << std::endl;
    }
    else {
        double metade = valor / 2;
        saldo -= valor;
        destino1.deposito(metade);
        destino2.deposito(metade);
        extrato[extratoIndex] = saldo;
        extratoIndex++;
    }
}

//Implementar funcao de extrato da conta
void BankAccount::exibirExtrato() const {
    std::cout << "=== Extrato da Conta " << conta << " ===\n";

    if(extratoIndex == 0) {
        std::cout << ": " << saldo << " :\n";
    } else {
        for(int i = 0; i < extratoIndex; i++) {
            std::cout << ": R$ " << extrato[i] << " :\n";
        }
    }
    std::cout << "=============================\n";
}

//Vai mostrar o saldo atual na conta do titular
void BankAccount::consultaSaldo() const{
    std::cout << "Saldo: R$" << saldo << std::endl; 
}

//Vai mostrar todos os dados do titular exceto o extrato
void BankAccount::dados() const{
    std::cout << "Saldo atual: R$" << saldo << std::endl;
    std::cout << "Conta: " << conta << std::endl;

    std::cout << "Nome: " << titular.getName() << std::endl;
    std::cout << "Cpf: " << titular.getCpf() << std::endl;
}

//Funćão usada para testes, usa um get pra acessar o valor do saldo
double BankAccount::getSaldo() const{
    return saldo;
}

//Getter para pegar numero da conta
int BankAccount::getNumeroConta() const {
    return conta;
}

//Getter para pegar nome do titular
std::string BankAccount::getTitularName() const {
    return titular.getName();
}


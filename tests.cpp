#include <iostream>
#include "user.hpp"
#include "bank_account.hpp"
using namespace std;

//Funcao para testar a igualdade dos valores retornados e valores esperados
void check(bool condition, const string &testName) {
    cout << testName << ": " << (condition ? "OK" : "Falhou") << endl;
}


int main() {
    cout << "[TESTES] Sistema Bancário" << endl;

    // Criação de usuários
    User user1("Angela RoRo", "038.629.911-05");
    User user2("Roberto Carlos", "865.053.519-49");
    User user3("Gal Costa", "392.489.995-90");

    // Criação de contas
    BankAccount conta1(user1, 1000, 12345);
    BankAccount conta2(user2, 1000, 54321);
    BankAccount conta3(user3, 1000, 98765);

    // Relatório inicial
    cout << "\n[TESTE] Criação de contas" << endl;
    cout << "Conta número " << conta1.getNumeroConta() 
        << " criada para: " << conta1.getTitularName() 
        << " | Saldo inicial: R$" << conta1.getSaldo() << endl;

    cout << "Conta número " << conta2.getNumeroConta() 
        << " criada para: " << conta2.getTitularName() 
        << " | Saldo inicial: R$" << conta2.getSaldo() << endl;

    cout << "Conta número " << conta3.getNumeroConta() 
        << " criada para: " << conta3.getTitularName() 
        << " | Saldo inicial: R$" << conta3.getSaldo() << endl;

    // Check saldo inicial
    check(conta1.getSaldo() == 1000, "Saldo inicial conta1");
    check(conta2.getSaldo() == 1000, "Saldo inicial conta2");
    check(conta3.getSaldo() == 1000, "Saldo inicial conta3");

    // Teste de depósito
    conta1.deposito(200);
    conta2.deposito(100);
    cout << "\n[TESTE] Depósitos" << endl;
    cout << "Saldo conta número " << conta1.getNumeroConta() << " após depósito: R$" << conta1.getSaldo() << endl;
    cout << "Saldo conta número " << conta2.getNumeroConta() << " após depósito: R$" << conta2.getSaldo() << endl;

    // Teste de saque
    conta1.saque(300);
    conta3.saque(2000); // saque maior que saldo
    cout << "\n[TESTE] Saques" << endl;
    cout << "Saldo conta" << conta1.getNumeroConta() << " após saque: R$" << conta1.getSaldo() << endl;
    cout << "Saldo conta" << conta3.getNumeroConta() << " após saque: R$" << conta3.getSaldo() << endl;
    check(conta1.getSaldo() == 900, "Saque conta1");
    check(conta3.getSaldo() == 1000, "Saque conta3 insuficiente");

    // Teste de transferência
    conta1.transferencia(400, conta2);
    conta2.transferencia(200, conta1, conta3);
    cout << "\n[TESTE] Transferências" << endl;
    cout << "Saldo conta1: R$" << conta1.getSaldo() << endl;
    cout << "Saldo conta2: R$" << conta2.getSaldo() << endl;
    cout << "Saldo conta3: R$" << conta3.getSaldo() << endl;

    check(conta1.getSaldo() == 600, "Transferência conta1");
    check(conta2.getSaldo() == 1300, "Transferência conta2");
    check(conta3.getSaldo() == 1100, "Transferência conta3");

    // Teste de extrato
    cout << "\n[TESTE] Extratos" << endl;
    conta1.exibirExtrato();
    conta2.exibirExtrato();
    conta3.exibirExtrato();

    return 0;
}
#include <iostream>
#include <vector>
#include "bank_account.hpp"
#include "auxiliary.hpp"

using namespace std;

int main() {
    vector<BankAccount> contas;// vetor que armazena todas as contas
    int proximoNumeroConta = 1;   // gera numeros para as contas (IDs)
    int opcao;

    do {
        cout << "\n<=== BANKING SYSTEM ===>\n";
        cout << "\n<=== MENU OPERAÇÕES ===>\n";
        cout << "1. Criar conta\n";
        cout << "2. Depositar\n";
        cout << "3. Sacar\n";
        cout << "4. Transferir\n";
        cout << "5. Transferir para duas contas\n";
        cout << "6. Extrato\n";
        cout << "0. Sair\n";
        cout << "Escolha uma opcao: ";
        cin >> opcao;

        switch(opcao) {
            case 1: criarConta(contas, proximoNumeroConta); break;
            case 2: depositar(contas); break;
            case 3: sacar(contas); break;
            case 4: transferir(contas); break;
            case 5: transferirParaDuasContas(contas); break;
            case 6: mostrarExtrato(contas); break;
            case 0: cout << "Saindo...\n"; break;
            default: cout << "Opcao invalida!\n"; break;
        }
    } while(opcao != 0);

    return 0;
}

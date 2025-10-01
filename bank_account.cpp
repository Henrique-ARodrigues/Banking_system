#include <iostream>
#include "bank_account.hpp"
//Incluindo o cabecalho, que ja tem o cabecalho de user tambem
//E a biblioteca da linguagem

//Faz o deposito na conta do titular
void Bank::deposito(double valor) {
    saldo += valor;
    //Salva o extrato depois de qualquer alteracao no saldo
    //Isso vai acontece em todas a funcoes que mexem diretamente no saldo
    //Decidimos implementar essa funcao, achamos que seria interessante
    extrato[extratoIndex] = saldo;
    extratoIndex++;
}
//Faz um saque na conta do titular 
void Bank::saque(double valor) {
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
void Bank::transferir(double valor, Bank &destino) {
    if(saldo < valor) {
        std::cout << "Sem saldo para essa quantia" << std::endl;
    }
    //Faz a transferencia da conta do titular para a conta destino
    else {
        saldo -= valor;
        destino.deposito(valor);
        destino.extrato[extratoIndex] = saldo;
        destino.extratoIndex++;
    }

}
//Faz uma transferencia de metade do valor que o titular tirou da conta dele
//E transfere igualmente para duas contas destino
void Bank::transferir(double valor, Bank &destino1, Bank &destino2) {
    if(saldo < valor) {
        std::cout << "Sem saldo para essa quantia" << std::endl;
    }
    else {
        double metade = valor / 2;
        saldo -= valor;
        destino1.deposito(metade);
        destino1.extrato[extratoIndex] = saldo;
        destino2.extratoIndex++;
        destino2.deposito(metade);
    }

}
//Implementar funcao de extrato da conta
void Bank::Mostra_extrato() {
    std::cout << "=== Extrato ===" << std::endl;
    for(int i = 0; i < extratoIndex; i++) {
        std::cout << ": " << extrato[i] << " :" << std::endl;

    }
    std::cout << "===============" << std::endl;

}
//Vai mostrar o saldo atual na conta do titular
void Bank::Mostra_saldo() const{
    std::cout << "Saldo atual: R$" << saldo << std::endl; 
}
//Vai mostrar todos os dados do titular exceto o extrato
void Bank::dados() const{
    std::cout << "Saldo atual: R$" << saldo << std::endl;
    std::cout << "Conta: " << conta << std::endl;

    std::cout << "Nome: " << titular.Getter_name() << std::endl;
    std::cout << "Cpf: " << titular.Getter_cpf() << std::endl;
}

#pragma once
#include "user.hpp"
//Usando o pragma
//para nao incluir mais de 1 vez
//Usando a User.hpp para colocar o titular

//Criando a classe do banco
class Bank {
    private:
        int conta;
        double saldo;
        Users titular;
        double extrato[25] = {0};
        int extratoIndex = 0;
    public:
        //Funcao para fazer o deposito na conta do titular
        void deposito(double valor);
        //Funcao para fazer o saque na conta do titular
        void saque(double valor);

        //Sobrecarga de funcao
        //A primeira vai transferir pra uma unica conta
        void transferir(double valor, Bank &destino);

        //Implementar funcao de extrato da conta
        void Mostra_extrato();
        //A segunda vai transferir o valor igualmente para duas contas
        //O valor tem que ser dividido igualmente para as duas contas
        void transferir(double valor, Bank &destino1, Bank &destino2);

        //Mostra o saldo na conta do titular
        void Mostra_saldo() const;
        //Mostra os dados do titular e da conta bancaria
        void dados() const;

};

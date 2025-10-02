#pragma once
#include "user.hpp"
//Usando o pragma
//para nao incluir mais de 1 vez
//Usando a User.hpp para colocar o titular

//Criando a classe do banco
class BankAccount {
    private:
        int conta;
        double saldo;
        User titular;
        double extrato[25] = {0};
        int extratoIndex = 0;

    public:

        //Construtor
        BankAccount(const User& user, double saldo_inicial, int numeroConta);

        //Funcao para fazer o deposito na conta do titular
        void deposito(double valor);

        //Funcao para fazer o saque na conta do titular
        void saque(double valor);

        //Sobrecarga de funcao
        //A primeira vai transferir pra uma unica conta
        void transferencia(double valor, BankAccount &destino);

        //A segunda vai transferir o valor igualmente para duas contas
        //O valor tem que ser dividido igualmente para as duas contas
        void transferencia(double valor, BankAccount &destino1, BankAccount &destino2);

        //Implementar funcao de extrato da conta
        void exibirExtrato();

        //Mostra o saldo na conta do titular
        void consultaSaldo() const;

        //Mostra os dados do titular e da conta bancaria
        void dados() const;

        //Getters auxiliares usados para testes:
        //Retorna o saldo
        double getSaldo() const;

        //Retorna numero da conta
        int getNumeroConta() const;  

        //Retorna nome do titular
        std::string getTitularName() const;

};

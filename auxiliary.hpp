#pragma once
#include <vector>
#include "bank_account.hpp"

// Declaração das funções auxiliares
//Usando o vetor BankAccount para testar o sistema
//e a usabilidade localmente
void criarConta(std::vector<BankAccount> &contas, int &proximoNumeroConta);
void depositar(std::vector<BankAccount> &contas);
void sacar(std::vector<BankAccount> &contas);
void transferir(std::vector<BankAccount> &contas);
void transferirParaDuasContas(std::vector<BankAccount> &contas);
void mostrarExtrato(const std::vector<BankAccount> &contas);

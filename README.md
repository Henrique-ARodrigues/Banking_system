# SISTEMA BANCÁRIO EM C++

Esse projeto é um sistema bancário simples, que realiza operações básicas como criar conta, depositar e sacar.
Feito como avaliação da primeira unidade da disciplina de Linguagem de Programação I

---

## Estrutura do Projeto

├── auxiliary.cpp/h # Funções auxiliares

├── bank_account.cpp/h # Implementação da classe BankAccount

├── user.cpp/h # Implementação da classe User

├── main.cpp # Programa principal

├── tests.cpp # Testes automáticos das funcionalidades

├── Makefile # Arquivo para compilar o projeto

└── README.md


---

## Compilação

O projeto utiliza um **Makefile** para facilitar a compilação. Para compilar tudo:

```bash
make

make run -> executa o programa principal onde é possível usar o sistema

make run-tests -> executa uma bateria de testes no sistema e mostra o resultado deles

make clean -> limpa o ambiente
 

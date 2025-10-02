#include "user.hpp"
//Incluindo o cabecalho

//Quando chamado vai retornar o que tem na parte privada
std::string User::getCpf() const{
    return cpf;
} 

std::string User::getName() const{
    return name;
}

//Vai receber os parametros
//E atribuir as variaveis
User::User(const std::string& name, const std::string& cpf) {
    this -> name = name;
    this -> cpf = cpf;
}
 

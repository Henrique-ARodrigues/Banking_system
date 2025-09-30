#include "user.hpp"
//Incluindo o cabecalho

//Quando chamado vai retornar o que tem na parte privada
int Users::Getter_cpf() const{
    return cpf;
} 

std::string Users::Getter_name() const{
    return name;
}
//Vai receber os parametros
//E atribuir as variaveis
Users::Users(const std::string& name, int cpf) {
    this -> name = name;
    this -> cpf = cpf;
}
 

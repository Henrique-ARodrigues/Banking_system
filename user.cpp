#include "user.hpp"


int Users::Getter_cpf() const{
    return cpf;
} 

std::string Users::Getter_name() const{
    return name;
}

Users::Users(const std::string& name, int cpf) {
    this -> name = name;
    this -> cpf = cpf;
}
 

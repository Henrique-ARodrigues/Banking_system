#pragma once
#include <string>
//Usei o pragma pra evitar incluir mais de 1 vez

//Criando a classe Users
class Users {
    private:
        int cpf;
        std::string name;

    public:

        //Criando Getters, 
        //Vai mostrar o que tem nas variaveis privadas
        int Getter_cpf() const;
        std::string Getter_name() const;

        //Construtor para inicializar as variaveis
        Users(const std::string& name, int cpf);
};

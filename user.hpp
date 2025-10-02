#pragma once
#include <string>
//Usei o pragma pra evitar incluir mais de 1 vez

//Criando a classe User
class User {
    private:
        std::string cpf;
        std::string name;

    public:

        //Criando Getters, 
        //Vai mostrar o que tem nas variaveis privadas
        std::string getCpf() const;
        std::string getName() const;

        //Construtor para inicializar as variaveis
        User(const std::string& name, const std::string& cpf);
};

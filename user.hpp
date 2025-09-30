#pragma once
#include <string>


class Users {
    private:
        int cpf;
        std::string name;

    public:

        //Criando Getters
        int Getter_cpf() const;
        std::string Getter_name() const;

        //Construtor
        Users(const std::string& name, int cpf);
};

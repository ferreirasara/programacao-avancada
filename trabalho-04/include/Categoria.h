#ifndef _CATEGORIA_
#define _CATEGORIA_

#include <string>

class Categoria {
public:
    Categoria(std::string nome) : _nome(nome) {}
    std::string getNome() { return _nome; }
private:
    std::string _nome;
};

#endif
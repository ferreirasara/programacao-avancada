#ifndef _ORCAMENTO_
#define _ORCAMENTO_

#include <string>
#include <iostream>
#include "Data.h"
#include "Hora.h"
#include "Categoria.h"

class Orcamento {
public:
    Orcamento(Categoria* categoria, Data* data, Hora* hora, double valor, std::string descricao) : _categoria(categoria), _data(data), _hora(hora), _valor(valor), _descricao(descricao) {};
    void mostrar() {
        std::cout << "Categoria: " << _categoria->getNome() << " - "
                  << "Dt: " << *_data << " " << *_hora << " - "
                  << "RS$" << _valor << " - "
                  << "Obs: " << _descricao << std::endl;
    }
    Categoria* getCategoria() { return _categoria; }
    double getValor() { return _valor; }
    Data* getData() { return _data; }
    Hora* getHora() { return _hora; }
    ~Orcamento() {};
private:
    std::string _descricao;
    double _valor;
    Data* _data;
    Hora* _hora;
    Categoria* _categoria;
};

bool maior(Orcamento* orcamento1, Orcamento* orcamento2) {
    return orcamento1->getValor() > orcamento2->getValor();
}

#endif
#ifndef _CATEGORIA_
#define _CATEGORIA_

#include <string>

class Categoria {
public:
    Categoria(std::string nome) : _nome(nome), _orcamentoTotal(0) {}
    Categoria(std::string nome, double orcamentoTotal) : _nome(nome), _orcamentoTotal(orcamentoTotal) {}
    std::string getNome() { return _nome; }
    double getOrcamentoTotal() { return _orcamentoTotal; }
    void setOrcamentoTotal(double orcamentoTotal) { _orcamentoTotal = orcamentoTotal; }
    ~Categoria() {};
private:
    std::string _nome;
    double _orcamentoTotal;
};

bool igual(Categoria* categoria1, Categoria* categoria2) {
    return categoria1->getNome().compare(categoria2->getNome()) == 0;
}

#endif
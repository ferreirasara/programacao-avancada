#ifndef _CONTROLE_CATEGORIA_
#define _CONTROLE_CATEGORIA_

#include <string>
#include <list>
#include "InterfaceSGDB.h"
#include "Categoria.h"

class ControleCategoria {
public:
    ControleCategoria() {};
    void adicionarCategoria(std::string nome, double orcamentoTotal) {
        InterfaceSGDB* interfaceSGDB;
        Categoria categoria(nome, orcamentoTotal);
        
        interfaceSGDB->adicionarCategoria(&categoria);
    }
    void excluirCategoria(std::string nome) {
        InterfaceSGDB* interfaceSGDB;
        Categoria categoria(nome);
        
        interfaceSGDB->excluirCategoria(&categoria);
    }
    void editarNomeCategoria(std::string nome, std::string novoNome) {
        InterfaceSGDB* interfaceSGDB;
        Categoria categoria(nome);
        
        interfaceSGDB->editarCategoria(&categoria, novoNome);
    }
    void editarOrcamentoCategoria(std::string nome, double orcamentoTotal) {
        InterfaceSGDB* interfaceSGDB;
        Categoria categoria(nome, orcamentoTotal);
        
        interfaceSGDB->editarCategoria(&categoria, orcamentoTotal);
    }
    std::list<Categoria> retornarListaCategorias() {
        InterfaceSGDB* interfaceSGDB;
        std::list<Categoria> categorias = interfaceSGDB->retornarListaCategorias();
        
        return categorias;
    }
};

#endif
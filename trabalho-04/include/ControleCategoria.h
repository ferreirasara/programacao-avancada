#ifndef _CONTROLE_CATEGORIA_
#define _CONTROLE_CATEGORIA_

#include <string>
#include <iostream>
#include <list>
#include "InterfaceSGDB.h"
#include "Categoria.h"

class ControleCategoria {
public:
    ControleCategoria() {};
    void adicionarCategoria(std::string nome) {
        InterfaceSGDB* interfaceSGDB;
        Categoria categoria(nome);
        interfaceSGDB->adicionarCategoria(&categoria);
    }
    void excluirCategoria(std::string nome) {
        InterfaceSGDB* interfaceSGDB;
        Categoria categoria(nome);
        interfaceSGDB->excluirCategoria(&categoria);
    }
    void editarCategoria(std::string nome, std::string novoNome) {
        InterfaceSGDB* interfaceSGDB;
        Categoria categoria(nome);
        interfaceSGDB->editarCategoria(&categoria, novoNome);
    }
    std::list<Categoria> retornarListaCategorias() {
        InterfaceSGDB* interfaceSGDB;
        std::list<Categoria> categorias = interfaceSGDB->retornarListaCategorias();
        return categorias;
    }
};

#endif
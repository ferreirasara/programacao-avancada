#ifndef _INTERFACE_SGDB_
#define _INTERFACE_SGDB_

#include <iostream>
#include <fstream>
#include <string>
#include <list>
#include "Categoria.h"
#include "SGDB.h"

class InterfaceSGDB {
public:
    InterfaceSGDB();
    void adicionarCategoria(Categoria* categoria) {
        SGDB* sgdb;
        sgdb->incluir("c", categoria->getNome());
        std::cout << "Categoria " << categoria->getNome() << " foi adicionada." << std::endl;
    }
    void excluirCategoria(Categoria* categoria) {
        SGDB* sgdb;
        sgdb->excluir("c", categoria->getNome());
        std::cout << "Categoria " << categoria->getNome() << " foi excluida." << std::endl;
    }
    void editarCategoria(Categoria* categoria) {
        SGDB* sgdb;
        sgdb->editar("c", categoria->getNome());
        std::cout << "Categoria " << categoria->getNome() << " foi editada." << std::endl;
    }
    std::list<Categoria> retornarListaCategorias() {
        std::list<Categoria> categorias;
        std::list<std::string> dados;
        SGDB* sgdb;
        dados = sgdb->ler("c");
        for (auto it = dados.begin(); it != dados.end(); it++) {
            Categoria c(*it);
            categorias.push_back(c);
        }
        return categorias;
    }
};

#endif
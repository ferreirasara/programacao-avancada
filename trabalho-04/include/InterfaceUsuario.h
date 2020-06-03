#ifndef _INTERFACE_USUARIO_
#define _INTERFACE_USUARIO_

#include <iostream>
#include <string>
#include <list>
#include "ControleCategoria.h"
#include "Categoria.h"

class InterfaceUsuario {
public:
    InterfaceUsuario();
    int exibirTelaInicial() {
        std::cout << "Escolha uma opcao:" << std::endl;
        std::cout << "1. Gerenciar Categorias" << std::endl;
        std::cout << ">: ";
        int opcao;
        std::cin >> opcao;
        
        return opcao;
    }
    int exibirGerenciarCategorias() {
        std::cout << "Escolha uma opcao:" << std::endl;
        std::cout << "1. Adicionar Categoria" << std::endl;
        std::cout << "2. Excluir Categoria" << std::endl;
        std::cout << "3. Editar Categoria" << std::endl;
        std::cout << ">: ";
        int opcao;
        std::cin >> opcao;

        return opcao;
    }
    std::string adicionarCategoria() {
        std::cout << "Digite um nome para a categoria:" << std::endl;
        std::cout << ">: ";
        std::string nome;
        std::cin >> nome;

        return nome;
    }
    std::string excluirCategoria(std::list<Categoria> categorias) {
        std::cout << "Categorias cadastradas:" << std::endl;
        for (auto it = categorias.begin(); it != categorias.end(); it++) {
            std::cout << it->getNome() << std::endl;
        }
        std::cout << "Qual categoria voce deseja excluir?" << std::endl;
        std::cout << ">: ";
        std::string nome;
        std::cin >> nome;

        return nome;
    }
    std::string editarCategoria(std::list<Categoria> categorias) {
        std::cout << "Categorias cadastradas:" << std::endl;
        for (auto it = categorias.begin(); it != categorias.end(); it++) {
            std::cout << it->getNome() << std::endl;
        }
        std::cout << "Qual categoria voce deseja editar?" << std::endl;
        std::cout << ">: ";
        std::string nome;
        std::cin >> nome;

        return nome;
    }
};

#endif
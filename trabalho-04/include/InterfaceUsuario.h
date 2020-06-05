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
        std::cout << "2. Consultar Orcamento" << std::endl;
        std::cout << ">: ";
        int opcao;
        std::cin >> opcao;
        
        return opcao;
    }
    int exibirGerenciarCategorias() {
        std::cout << std::endl << "Escolha uma opcao:" << std::endl;
        std::cout << "1. Adicionar Categoria" << std::endl;
        std::cout << "2. Excluir Categoria" << std::endl;
        std::cout << "3. Editar Categoria" << std::endl;
        std::cout << ">: ";
        int opcao;
        std::cin >> opcao;

        return opcao;
    }
    std::string adicionarCategoria() {
        std::cout << std::endl << "Digite um nome para a categoria:" << std::endl;
        std::cout << ">: ";
        std::string nome;
        std::cin >> nome;

        return nome;
    }
    std::string excluirCategoria(std::list<Categoria> categorias) {
        std::cout << std::endl << "Categorias cadastradas:" << std::endl;
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
        std::cout << std::endl << "Categorias cadastradas:" << std::endl;
        for (auto it = categorias.begin(); it != categorias.end(); it++) {
            std::cout << it->getNome() << std::endl;
        }
        std::cout << "Qual categoria voce deseja editar?" << std::endl;
        std::cout << ">: ";
        std::string nome;
        std::cin >> nome;

        return nome;
    }
    std::string renomearCategoria() {
        std::cout << "Digite o novo nome para a categoria:" << std::endl;
        std::cout << ">: ";
        std::string novoNome;
        std::cin >> novoNome;

        return novoNome;
    }
    void exibirMensagem(std::string texto) {
        std::cout << texto << std::endl;
    }
    void exibirOrcamentos(std::list<Orcamento*> orcamentos) {
        std::cout << std::endl << "Orcamentos:" << std::endl;
        for (auto it = orcamentos.begin(); it != orcamentos.end(); it++) {
            // std::cout << (*it)->getValor() << std::endl;
            (*it)->mostrar();
        }
    }
    std::string consultarOrcamento() {
        std::cout << std::endl << "Digite a data inicial no formato DD/MM/AAAA:" << std::endl;
        std::cout << ">:";
        std::string dataInicial;
        std::cin >> dataInicial;

        std::cout << std::endl << "Digite a data final no formato DD/MM/AAAA:" << std::endl;
        std::cout << ">:";
        std::string dataFinal;
        std::cin >> dataFinal;

        return dataInicial+"-"+dataFinal;
    }

};

#endif
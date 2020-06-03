#ifndef _CONTROLE_USUARIO_
#define _CONTROLE_USUARIO_

#include <string>
#include <iostream>
#include <list>
#include "InterfaceUsuario.h"
#include "ControleCategoria.h"

class ControleUsuario {
public:
    ControleUsuario();
    void executar() {
        InterfaceUsuario* interfaceUsuario;
        int opcao = interfaceUsuario->exibirTelaInicial();

        if (opcao == 1) { // Gerenciar categorias
            ControleCategoria* controleCategoria;
            opcao = interfaceUsuario->exibirGerenciarCategorias();
            if (opcao == 1) {
                std::string nome = interfaceUsuario->adicionarCategoria();
                controleCategoria->adicionarCategoria(nome);
            } else if (opcao == 2) {
                std::string nome = interfaceUsuario->excluirCategoria(controleCategoria->retornarListaCategorias());
                controleCategoria->excluirCategoria(nome);
            } else if (opcao == 3) {
                std::string nome = interfaceUsuario->editarCategoria(controleCategoria->retornarListaCategorias());
                controleCategoria->editarCategoria(nome);
            }
        }
    }
};

#endif
#ifndef _CONTROLE_USUARIO_
#define _CONTROLE_USUARIO_

#include <string>
#include <iostream>
#include <list>
#include "InterfaceUsuario.h"
#include "ControleCategoria.h"
#include "ControleOrcamento.h"
#include "Data.h"

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
                interfaceUsuario->exibirMensagem("Categoria "+nome+" foi adicionada.");
            } else if (opcao == 2) {
                std::string nome = interfaceUsuario->excluirCategoria(controleCategoria->retornarListaCategorias());
                controleCategoria->excluirCategoria(nome);
                interfaceUsuario->exibirMensagem("Categoria "+nome+" foi excluida.");
            } else if (opcao == 3) {
                std::string nome = interfaceUsuario->editarCategoria(controleCategoria->retornarListaCategorias());
                std::string novoNome = interfaceUsuario->renomearCategoria();
                controleCategoria->editarCategoria(nome, novoNome);
                interfaceUsuario->exibirMensagem("Categoria "+nome+" foi alterada para "+novoNome+".");
            }
        } else if (opcao == 2) {
            std::string periodo = interfaceUsuario->consultarOrcamento();
            // Data dataInicial(periodo.substr(0,10));
            // Data dataFinal(periodo.substr(11,10));

            Data dataInicial(1,6,2020);
            Data dataFinal(30,6,2020);

            ControleOrcamento* controleOrcamento;
            std::list<Orcamento*> orcamentos = controleOrcamento->consultarOrcamento(&dataInicial, &dataFinal);

            interfaceUsuario->exibirOrcamentos(orcamentos);
        }
    }
};

#endif
#ifndef _CONTROLE_USUARIO_
#define _CONTROLE_USUARIO_

#include <string>
#include <list>
#include "InterfaceUsuario.h"
#include "ControleCategoria.h"
#include "ControleOrcamento.h"
#include "ControleRelatorio.h"
#include "InterfaceImpressora.h"
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
                std::string nome = interfaceUsuario->solicitarNomeCategoria();
                double orcamento = interfaceUsuario->solicitarOrcamentoCategoria();

                controleCategoria->adicionarCategoria(nome, orcamento);
            
                interfaceUsuario->exibirMensagem("Categoria "+nome+" foi adicionada.");
            } else if (opcao == 2) {
                std::string nome = interfaceUsuario->excluirCategoria(controleCategoria->retornarListaCategorias());
                
                controleCategoria->excluirCategoria(nome);
            
                interfaceUsuario->exibirMensagem("Categoria "+nome+" foi excluida.");
            } else if (opcao == 3) {
                std::string nome = interfaceUsuario->editarCategoria(controleCategoria->retornarListaCategorias());
                std::string novoNome = interfaceUsuario->renomearCategoria();
                
                controleCategoria->editarNomeCategoria(nome, novoNome);
            
                interfaceUsuario->exibirMensagem("Categoria "+nome+" foi alterada para "+novoNome+".");
            }
        } else if (opcao == 2) { // Consultar orcamento
            std::string periodo = interfaceUsuario->consultarOrcamento();
            Data dataInicial(periodo.substr(0,10));
            Data dataFinal(periodo.substr(11,10));

            ControleOrcamento* controleOrcamento;
            std::list<Orcamento*> orcamentos = controleOrcamento->consultarOrcamento(&dataInicial, &dataFinal);

            interfaceUsuario->exibirOrcamentos(orcamentos);
        } else if (opcao == 3) { // Relatorios
            opcao = interfaceUsuario->exibirSelecionarRelatorio();
            ControleRelatorio* controleRelatorio;
            InterfaceImpressora* interfaceImpressora;
            if (opcao == 1) {
                std::string mesAno = interfaceUsuario->solicitarMesRelatorio();
                if (mesAno.length() != 7) {
                    mesAno = "0"+mesAno;
                }
                
                Data dataInicial("01/"+mesAno);
                Data dataFinal("31/"+mesAno);
                
                std::list<std::string> relatorio = controleRelatorio->gastosMensaisPorCategoria(&dataInicial, &dataFinal);
                
                interfaceUsuario->exibirMensagem("\nImprimindo...");
                interfaceImpressora->imprimirRelatorio(relatorio, "Gastos mensais por categoria - "+mesAno);
            } else if (opcao == 2) {
                std::string ano = interfaceUsuario->solicitarAnoRelatorio();
               
                Data dataInicial("01/01/"+ano);
                Data dataFinal("31/12/"+ano);
                
                std::list<std::string> relatorio = controleRelatorio->gastosDuranteOPeriodoDeUmAno(&dataInicial, &dataFinal);
                
                interfaceUsuario->exibirMensagem("\nImprimindo...");
                interfaceImpressora->imprimirRelatorio(relatorio, "Gastos Anuais - "+ano);
            } else if (opcao == 3) {
                std::string ano = interfaceUsuario->solicitarAnoRelatorio();
                
                Data dataInicial("01/01/"+ano);
                Data dataFinal("31/12/"+ano);
                
                std::list<std::string> relatorio = controleRelatorio->rankingComOsMaioresGastosNoAno(&dataInicial, &dataFinal);
                
                interfaceUsuario->exibirMensagem("\nImprimindo...");
                interfaceImpressora->imprimirRelatorio(relatorio, "Ranking dos 10 maiores gastos do ano - "+ano);
            } else if (opcao == 4) {
                std::string mesAno = interfaceUsuario->solicitarMesRelatorio();
                if (mesAno.length() != 7) {
                    mesAno = "0"+mesAno;
                }
                
                Data dataInicial("01/"+mesAno);
                Data dataFinal("31/"+mesAno);
                
                std::list<std::string> relatorio = controleRelatorio->categoriaQueUltrapassaramOOrcamentoPorMes(&dataInicial, &dataFinal);
                
                interfaceUsuario->exibirMensagem("\nImprimindo...");
                interfaceImpressora->imprimirRelatorio(relatorio, "Categorias que ultrapassaram o orcamento - "+mesAno);
            }
        }
    }
};

#endif
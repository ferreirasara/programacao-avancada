#ifndef _CONTROLE_RELATORIO_
#define _CONTROLE_RELATORIO_

#include <string>
#include <list>
#include "InterfaceSGDB.h"
#include "Orcamento.h"
#include "Categoria.h"
#include "Data.h"

class ControleRelatorio {
public:
    ControleRelatorio() {};
    std::list<std::string> gastosMensaisPorCategoria(Data* dataInicial, Data* dataFinal) {
        InterfaceSGDB* _interfaceSGDB;
        std::list<std::string> relatorio;
        std::list<Orcamento*> orcamentos = _interfaceSGDB->consultarOrcamento(dataInicial, dataFinal);
        std::list<Categoria*> categorias;
       
        for (auto itOrcamento = orcamentos.begin(); itOrcamento != orcamentos.end(); itOrcamento++) {
            categorias.push_front((*itOrcamento)->getCategoria());
        }
        
        categorias.unique(igual);
        
        for (auto itCategoria = categorias.begin(); itCategoria != categorias.end(); itCategoria++) {
            double valorTotal = 0;
            std::string linhaRelatorio;
            
            for (auto itOrcamento = orcamentos.begin(); itOrcamento != orcamentos.end(); itOrcamento++) {
                if (igual((*itOrcamento)->getCategoria(), (*itCategoria))) {
                    valorTotal += (*itOrcamento)->getValor();
                }
            }
            
            linhaRelatorio = (*itCategoria)->getNome() + " - " + to_string(valorTotal);
            
            relatorio.push_back(linhaRelatorio);
        }
        
        return relatorio;
    };
    std::list<std::string> gastosDuranteOPeriodoDeUmAno(Data* dataInicial, Data* dataFinal) {
        InterfaceSGDB* _interfaceSGDB;
        std::list<Orcamento*> orcamentos = _interfaceSGDB->consultarOrcamento(dataInicial, dataFinal);
        double valorTotal = 0;
        std::list<std::string> relatorio;
        
        for (auto itOrcamento = orcamentos.begin(); itOrcamento != orcamentos.end(); itOrcamento++) {
            valorTotal += (*itOrcamento)->getValor();
            std::string linha = to_string((*itOrcamento)->getData()->getDia())+"/"+
                                to_string((*itOrcamento)->getData()->getMes())+"/"+
                                to_string((*itOrcamento)->getData()->getAno())+" - "+
                                (*itOrcamento)->getCategoria()->getNome()+" - R$"+
                                to_string((*itOrcamento)->getValor());
            
            relatorio.push_back(linha);
        }
        
        relatorio.push_back("\nTotal: R$"+to_string(valorTotal));
        
        return relatorio;
    };
    std::list<std::string> rankingComOsMaioresGastosNoAno(Data* dataInicial, Data* dataFinal) {
        InterfaceSGDB* _interfaceSGDB;
        std::list<Orcamento*> orcamentos = _interfaceSGDB->consultarOrcamento(dataInicial, dataFinal);
        orcamentos.sort(maior);
        
        std::list<std::string> relatorio;
        int contador = 0;
        for (auto itOrcamento = orcamentos.begin(); itOrcamento != orcamentos.end(); itOrcamento++) {
            if (contador < 10) {
                std::string linha = to_string((*itOrcamento)->getData()->getDia())+"/"+
                                    to_string((*itOrcamento)->getData()->getMes())+"/"+
                                    to_string((*itOrcamento)->getData()->getAno())+" - "+
                                    (*itOrcamento)->getCategoria()->getNome()+" - R$"+
                                    to_string((*itOrcamento)->getValor());
                
                relatorio.push_back(linha);
                contador++;
            } else {
                break;
            }
        }

        return relatorio;
    };
    std::list<std::string> categoriaQueUltrapassaramOOrcamentoPorMes(Data* dataInicial, Data* dataFinal) {
        InterfaceSGDB* _interfaceSGDB;
        std::list<Orcamento*> orcamentos = _interfaceSGDB->consultarOrcamento(dataInicial, dataFinal);
        std::list<std::string> relatorio;
        std::list<Categoria> categorias = _interfaceSGDB->retornarListaCategorias();
       
       for (auto itCategoria = categorias.begin(); itCategoria != categorias.end(); itCategoria++) {
            double valorTotal = 0;
            
            for (auto itOrcamento = orcamentos.begin(); itOrcamento != orcamentos.end(); itOrcamento++) {
                if (itCategoria->getNome().compare((*itOrcamento)->getCategoria()->getNome()) == 0) {
                    valorTotal += (*itOrcamento)->getValor();
                }
            }
           
            if (valorTotal > itCategoria->getOrcamentoTotal()) {
                std::string linha = itCategoria->getNome()+
                                    " - Orcamento Disponivel: R$"+to_string(itCategoria->getOrcamentoTotal())+
                                    " Total gasto: R$"+to_string(valorTotal);
                
                relatorio.push_back(linha);
            }
        }

        return relatorio;
    }
};

#endif
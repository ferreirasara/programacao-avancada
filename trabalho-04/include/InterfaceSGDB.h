#ifndef _INTERFACE_SGDB_
#define _INTERFACE_SGDB_

#include <iostream>
#include <fstream>
#include <string>
#include <list>
#include "Categoria.h"
#include "Orcamento.h"
#include "SGDB.h"
#include "Data.h"

class InterfaceSGDB {
public:
    InterfaceSGDB();
    void adicionarCategoria(Categoria* categoria) {
        SGDB* _sgdb;
        _sgdb->incluir("c", categoria->getNome()+"-"+to_string(categoria->getOrcamentoTotal()));
    }
    void excluirCategoria(Categoria* categoria) {
        SGDB* _sgdb;
        _sgdb->excluir("c", categoria->getNome());
    }
    void editarCategoria(Categoria* categoria, std::string novoNome) {
        SGDB* _sgdb;
        _sgdb->editar("c", categoria->getNome(), novoNome);
    }
    void editarCategoria(Categoria* categoria, double orcamentoTotal) {
        SGDB* _sgdb;
        _sgdb->editar("c", categoria->getNome(), categoria->getNome()+"-"+to_string(orcamentoTotal));
    }
    std::list<Categoria> retornarListaCategorias() {
        SGDB* _sgdb;
        std::list<Categoria> categorias;
        std::list<std::string> dados;
        dados = _sgdb->ler("c");
        
        for (auto it = dados.begin(); it != dados.end(); it++) {
            std::size_t posicaoSeparador = (*it).find("-");
            std::string nome = (*it).substr(0, posicaoSeparador);
            double orcamento = atoi((*it).substr(posicaoSeparador+1, ((*it).length() - posicaoSeparador)).c_str());
            Categoria c(nome, orcamento);
            categorias.push_back(c);
        }
        
        return categorias;
    }
    std::list<Orcamento*> consultarOrcamento(Data* dataInicial, Data* dataFinal) {
        SGDB* _sgdb;
        std::list<Orcamento*> orcamentos;
        std::list<std::string> dados;
        dados = _sgdb->ler("o", dataInicial, dataFinal);
        
        for (auto it = dados.begin(); it != dados.end(); it++) {
            // Retorna as informacoes do orcamento. Ex: Mercado-04/06/2020-13:40-50.78-Descricao
            std::string linha = *it;

            Categoria* categoria = new Categoria(linha.substr(0,linha.find("-")));
            linha.erase(0,linha.find("-")+1);
            
            Data* data = new Data(linha.substr(0, 10));
            linha.erase(0,linha.find("-")+1);

            Hora* hora = new Hora(linha.substr(0, 5));
            linha.erase(0,linha.find("-")+1);

            double valor = atof(linha.substr(0,linha.find("-")+1).c_str());
            linha.erase(0,linha.find("-")+1);

            std::string descricao = linha.substr(0, linha.length());
            
            Orcamento* o = new Orcamento(categoria, data, hora, valor, descricao);
            
            orcamentos.push_front(o);

            o->~Orcamento();
            categoria->~Categoria();
            data->~Data();
            hora->~Hora();
        }

        return orcamentos;
    }
};

#endif
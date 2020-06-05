#ifndef _SGDB_
#define _SGDB_

#include <iostream>
#include <fstream>
#include <string>
#include <list>

class SGDB {
public:
    SGDB();
    void incluir(const char* tipo, std::string texto) {
        // formato das linhas -> c-Categoria 
        // c e o tipo (c para categoria, o para orcamento)
        // - separador
        // nome da categoria, ou dados do orcamento
        // exemplos
        // c-Mercado
        // o-Mercado-04/06/2020-50.78
        std::ofstream arquivo("dados.txt", std::ios_base::app);
        arquivo << tipo << "-" << texto << "\n";
    }
    void editar(const char* tipo, std::string texto, std::string novoTexto) {
        std::ifstream arquivoOld("dados.txt");
        std::string linha;
        std::string separador = "-";
        std::string linhaDesejada = tipo + separador + texto;
        std::list<std::string> dados;
        while (arquivoOld >> linha) {
            if (linha == linhaDesejada) {
                std::string novaLinha = tipo + separador + novoTexto;
                dados.push_back(novaLinha);
            } else {
                dados.push_back(linha);
            }
        }
        std::ofstream arquivo("dados.txt", std::ios_base::out);
        for (auto it = dados.begin(); it != dados.end(); it++) {
            arquivo << *it << "\n";
        }
    }
    void excluir(const char* tipo, std::string texto) {
        std::ifstream arquivoOld("dados.txt");
        std::string linha;
        std::string separador = "-";
        std::string linhaDesejada = tipo + separador + texto;
        std::list<std::string> dados;
        while (arquivoOld >> linha) {
            if (linha != linhaDesejada) {
                dados.push_back(linha);
            }
        }
        std::ofstream arquivo("dados.txt", std::ios_base::out);
        for (auto it = dados.begin(); it != dados.end(); it++) {
            arquivo << *it << "\n";
        }
    }
    std::list<std::string> ler(const char* tipo) {
        std::ifstream arquivo("dados.txt");
        std::string linha;
        std::list<std::string> dados;
        while (arquivo >> linha) {
            if (linha.substr(0, 1) == tipo) {
                // Retorna os nomes das categorias
                dados.push_back(linha.substr(2, linha.length()));
            }
        }
        return dados;
    }
    std::list<std::string> ler(const char* tipo, Data* dataInicial, Data* dataFinal) {
        std::ifstream arquivo("dados.txt");
        std::string linha;
        std::list<std::string> dados;
        while (arquivo >> linha) {
            if (linha.substr(0, 1) == tipo) {
                // formato de orçamento -> o-Mercado-04/06/2020-13:40-50.78-Descricao
                int posicaoData = linha.substr(2, linha.length()).find("-") + 3;
                Data dataOrcamento(linha.substr(posicaoData, 10));
                if (dataOrcamento >= dataInicial && dataOrcamento <= dataFinal) {
                    // Retorna as informacoes do orcamento. Ex: Mercado-04/06/2020-13:40-50.78-Descricao
                    dados.push_back(linha.substr(2, linha.length()));
                }
            }
        }
        return dados;
    }
};

#endif
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
        std::ofstream arquivo("dados.txt", std::ios_base::app);
        arquivo << tipo << "-" << texto << "\n";
    }
    void editar(const char* tipo, std::string texto) {
        std::ifstream arquivoOld("dados.txt");
        std::string linha;
        std::string separador = "-";
        std::string linhaDesejada = tipo + separador + texto;
        std::list<std::string> dados;
        while (arquivoOld >> linha) {
            if (linha == linhaDesejada) {
                dados.push_back(linhaDesejada);
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
                dados.push_back(linha.substr(2, linha.length()));
            }
        }
        return dados;
    }
};

#endif
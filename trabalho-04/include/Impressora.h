#ifndef _IMPRESSORA_
#define _IMPRESSORA_

#include <iostream>
#include <fstream>
#include <string>
#include <list>

class Impressora {
public:
    Impressora();
    void imprimir(std::string titulo) {
        std::cout << "Relatorio: " << titulo << std::endl;
    }
    void imprimir(std::list<std::string> lista) {
        for (auto it = lista.begin(); it != lista.end(); it++) {
            std::cout << *it << "\n";
        }
    }
};

#endif
#ifndef _INTERFACE_IMPRESSORA_
#define _INTERFACE_IMPRESSORA_

#include <iostream>
#include <fstream>
#include <string>
#include <list>
#include "Impressora.h"


class InterfaceImpressora {
public:
    InterfaceImpressora();
    void imprimirRelatorio(std::list<std::string> relatorio, std::string titulo) {
        Impressora* impressora;
        impressora->imprimir(titulo);
        impressora->imprimir(relatorio);
    }
};

#endif
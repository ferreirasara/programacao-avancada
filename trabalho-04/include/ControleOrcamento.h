#ifndef _CONTROLE_ORCAMENTO_
#define _CONTROLE_ORCAMENTO_

#include <string>
#include <iostream>
#include <list>
#include "InterfaceSGDB.h"
#include "Orcamento.h"
#include "Data.h"

class ControleOrcamento {
public:
    ControleOrcamento() {};
    std::list<Orcamento*> consultarOrcamento(Data* dataInicial, Data* dataFinal) {
        InterfaceSGDB* interfaceSGDB;
        std::list<Orcamento*> orcamentos = interfaceSGDB->consultarOrcamento(dataInicial, dataFinal);

        return orcamentos;
    }
};

#endif
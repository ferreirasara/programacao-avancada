#ifndef _CONTACORRENTE_H_
#define _CONTACORRENTE_H_

#include <iostream>
#include "Conta.h"

using namespace std;

class ContaCorrente : public Conta {
public:
    ContaCorrente(int numero, Cliente cliente) : Conta(numero, cliente) {}
    void aplicaJurosDiarios(int dias) {
        for (int i = 0; i < dias; ++i) {
            _saldo += _saldo * 0.00001;
        }
    }
};

#endif
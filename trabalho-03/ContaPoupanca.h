#ifndef _CONTAPOUPANCA_H_
#define _CONTAPOUPANCA_H_

#include <iostream>
#include "Conta.h"

using namespace std;

class ContaPoupanca : public Conta {
public:
    ContaPoupanca(int numero, Cliente* cliente) : Conta(numero, cliente) {}
    void aplicaJurosDiarios(int dias) {
        for (int i = 0; i < dias; ++i) {
            _saldo += _saldo * 0.00008;
        }
    }
};

#endif
#ifndef _CONTA_H_
#define _CONTA_H_

#include <iostream>
#include "Cliente.h"

using namespace std;

class Conta {
public:
    Conta(int numero, Cliente cliente) : _numero(numero), _cliente(cliente), _saldo(0) {
        cout << "Criando conta " << numero << " do cliente " << cliente.getNome() << endl;
    }
    void depositaValor(float valor) {
        _saldo += int(valor * 100);
    }
    void retira(float valor) {
        _saldo -= int(valor * 100);
    }
    void transfere(float valor, Conta contaDestino) {
        contaDestino.depositaValor(valor);
        retira(valor);
    }
    float getSaldo() {
        return _saldo / 100.0;
    }
    void extrato() {
        cout << "Conta numero " << _numero << " Saldo: R$ " << getSaldo() << endl;
    }
    virtual void aplicaJurosDiarios(int dias) {
        cerr << "ERROR";
    }
protected:
    int _numero;
    int _saldo;
    Cliente _cliente;
};

#endif
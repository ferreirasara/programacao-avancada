#ifndef _DATA_H_
#define _DATA_H_

#include "VetorInt.h"
#include <iostream>

using namespace std;

class Data : private VetorInt {
public:
    Data() : VetorInt(3) {}
    Data(int dia, int mes, int ano) : VetorInt(3) {
        _vetor[0] = dia;
        _vetor[1] = mes;
        _vetor[2] = ano;
    }
    Data operator+(const Data &outra) {
        Data dataNova(_vetor[0] + outra._vetor[0],
                      _vetor[1] + outra._vetor[1],
                      _vetor[2] + outra._vetor[2]);
        dataNova.corrigeData();
        return dataNova;
    }
    Data operator-(const Data &outra) {
        Data dataNova(_vetor[0] - outra._vetor[0],
                      _vetor[1] - outra._vetor[1],
                      _vetor[2] - outra._vetor[2]);
        dataNova.corrigeData();
        return dataNova;
    }
    bool operator==(const Data &outra) {
        return _vetor[0] == outra._vetor[0] && _vetor[1] == outra._vetor[1] && _vetor[2] == outra._vetor[2];
    }
    void operator+=(const Data &outra) {
        _vetor[0] += outra._vetor[0];
        _vetor[1] += outra._vetor[1];
        _vetor[2] += outra._vetor[2];
        this->corrigeData();
    }
    void operator-=(const Data &outra) {
        _vetor[0] -= outra._vetor[0];
        _vetor[1] -= outra._vetor[1];
        _vetor[2] -= outra._vetor[2];
        this->corrigeData();
    }
    bool operator!=(const Data &outra) { return !operator==(outra); }
    int operator[](const int posicao) { return _vetor[posicao]; }
    int operator()(const int posicao) { return _vetor[posicao]; }
    bool dataValida() {
        return diaValido() && mesValido();
    }
    bool mesValido() {
        return _vetor[1] <= 12 ? true : false;
    }
    bool diaValido() {
        if (_vetor[1] == 2) {
            return _vetor[0] <= 28 ? true : false;
        } else if (_vetor[0] == 1 || _vetor[0] == 3 || _vetor[0] == 5 || _vetor[0] == 7 || _vetor[0] == 8 || _vetor[0] == 10 || _vetor[0] == 12) {
            return _vetor[0] <= 31 ? true : false;
        } else {
            return _vetor[0] <= 30 ? true : false;
        }
    }
    void corrigeData() {
        while (!dataValida()) {
            if (!mesValido()) { corrigeMes(); }
            if (!diaValido()) { corrigeDia(); }
        }
    }
    void corrigeMes() {
        _vetor[1] = _vetor[1] - 12;
        _vetor[2]++;
    }
    void corrigeDia() {
        if (_vetor[1] == 2) {
            _vetor[0] = _vetor[0] - 28;
            _vetor[1]++; 
        } else if (_vetor[0] == 1 || _vetor[0] == 3 || _vetor[0] == 5 || _vetor[0] == 7 || _vetor[0] == 8 || _vetor[0] == 10 || _vetor[0] == 12) {
            _vetor[0] = _vetor[0] - 31;
            _vetor[1]++;
        } else {
            _vetor[0] = _vetor[0] - 30;
            _vetor[1]++;
        }
    }
    void imprime() { cout << _vetor[0] << "/" << _vetor[1] << "/" << _vetor[2] << endl; }
};

#endif
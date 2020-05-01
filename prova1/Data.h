#ifndef _DATA_H_
#define _DATA_H_

#include "VetorInt.h"
#include <iostream>
#include <iomanip>

using namespace std;

class Data : private VetorInt {
public:
    Data() : VetorInt(3) {}
    Data(int dia, int mes, int ano) : VetorInt(3) {
        _vetor[0] = dia;
        _vetor[1] = mes;
        _vetor[2] = ano;
        this->corrigeData();
    }
    Data operator+(const Data &outra) {
        VetorInt vetor = VetorInt::operator+(outra);
        Data dataNova(vetor[0], vetor[1], vetor[2]);
        dataNova.corrigeData();
        return dataNova;
    }
    Data operator-(const Data &outra) {
        VetorInt vetor = VetorInt::operator-(outra);
        Data dataNova(vetor[0], vetor[1], vetor[2]);
        dataNova.corrigeData();
        return dataNova;
    }
    void operator+=(const Data &outra) {
        VetorInt::operator+=(outra);
        this->corrigeData();
    }
    void operator-=(const Data &outra) {
        VetorInt::operator-=(outra);
        this->corrigeData();
    }
    bool operator==(Data &outra) { return VetorInt::operator==(outra); }
    bool operator!=(Data &outra) { return VetorInt::operator!=(outra); }
    int operator[](const int posicao) { return VetorInt::operator[](posicao); }
    int operator()(const int posicao) { return VetorInt::operator()(posicao); }
    bool dataValida() { return diaValido() && mesValido(); }
    bool mesValido() { return _vetor[1] <= 12 ? true : false; }
    bool diaValido() {
        if (_vetor[1] == 2) {
            return _vetor[0] <= 28 ? true : false;
        } else if (_vetor[1] == 1 || _vetor[1] == 3 || _vetor[1] == 5 || _vetor[1] == 7 || _vetor[1] == 8 || _vetor[1] == 10 || _vetor[1] == 12) {
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
        } else if (_vetor[1] == 1 || _vetor[1] == 3 || _vetor[1] == 5 || _vetor[1] == 7 || _vetor[1] == 8 || _vetor[1] == 10 || _vetor[1] == 12) {
            _vetor[0] = _vetor[0] - 31;
            _vetor[1]++;
        } else {
            _vetor[0] = _vetor[0] - 30;
            _vetor[1]++;
        }
    }
    void imprime() { cout << setw(2) << setfill('0') << _vetor[0] << "/" 
                          << setw(2) << setfill('0') << _vetor[1] << "/"
                          << setw(4) << setfill('0') << _vetor[2] << endl; }
};

#endif
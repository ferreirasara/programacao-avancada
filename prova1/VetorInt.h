#ifndef _VETORINT_H_
#define _VETORINT_H_

#include "Imprimivel.h"
#include <iostream>
#include <cstdlib>

class VetorInt : public Imprimivel {
public:
    VetorInt(int tamanho) : _tamanho(tamanho) { 
        _vetor = (int *) malloc(tamanho * sizeof(int));
        for (int i = 0; i < _tamanho; ++i) {
            _vetor[i] = rand() % 10;
        }
    }
    void imprime() {
        for (int i = 0; i < _tamanho; ++i) {
            std::cout << "[" << _vetor[i] << "] ";
        }
        std::cout << std::endl;
    }
    VetorInt operator+(const VetorInt &outro) {
        if (_tamanho > outro._tamanho) {
            VetorInt vetorNovo(_tamanho);
            for (int i = 0; i < _tamanho; ++i) {
                vetorNovo._vetor[i] = i < outro._tamanho ? _vetor[i] + outro._vetor[i] : _vetor[i];
            }
            return vetorNovo;
        } else {
            VetorInt vetorNovo(outro._tamanho);
            for (int i = 0; i < outro._tamanho; ++i) {
                vetorNovo._vetor[i] = i < _tamanho ? _vetor[i] + outro._vetor[i] : outro._vetor[i];
            }
            return vetorNovo;
        }
    }
    VetorInt operator-(const VetorInt &outro) {
        if (_tamanho > outro._tamanho) {
            VetorInt vetorNovo(_tamanho);
            for (int i = 0; i < _tamanho; ++i) {
                vetorNovo._vetor[i] = i < outro._tamanho ? _vetor[i] - outro._vetor[i] : _vetor[i];
            }
            return vetorNovo;
        } else {
            VetorInt vetorNovo(outro._tamanho);
            for (int i = 0; i < outro._tamanho; ++i) {
                vetorNovo._vetor[i] = i < _tamanho ? _vetor[i] - outro._vetor[i] : outro._vetor[i];
            }
            return vetorNovo;
        }
    }
    VetorInt operator*(const VetorInt &outro) {
        if (_tamanho > outro._tamanho) {
            VetorInt vetorNovo(_tamanho);
            for (int i = 0; i < _tamanho; ++i) {
                vetorNovo._vetor[i] = i < outro._tamanho ? _vetor[i] * outro._vetor[i] : _vetor[i];
            }
            return vetorNovo;
        } else {
            VetorInt vetorNovo(outro._tamanho);
            for (int i = 0; i < outro._tamanho; ++i) {
                vetorNovo._vetor[i] = i < _tamanho ? _vetor[i] * outro._vetor[i] : outro._vetor[i];
            }
            return vetorNovo;
        }
    }
    VetorInt operator*(const int escalar) {
        VetorInt vetorNovo(_tamanho);
        for (int i = 0; i < _tamanho; ++i) {
            vetorNovo._vetor[i] = _vetor[i] * escalar;
        }
        return vetorNovo;
    }
    void operator+=(const VetorInt &outro) {
        if (_tamanho > outro._tamanho) {
            for (int i = 0; i < outro._tamanho; ++i) {
                _vetor[i] += outro._vetor[i];
            }
        } else {
            for (int i = 0; i < _tamanho; ++i) {
                _vetor[i] += outro._vetor[i];
            }
        }
    }
    void operator-=(const VetorInt &outro) {
        if (_tamanho > outro._tamanho) {
            for (int i = 0; i < outro._tamanho; ++i) {
                _vetor[i] -= outro._vetor[i];
            }
        } else {
            for (int i = 0; i < _tamanho; ++i) {
                _vetor[i] -= outro._vetor[i];
            }
        }
    }
    void operator*=(const VetorInt &outro) {
        if (_tamanho > outro._tamanho) {
            for (int i = 0; i < outro._tamanho; ++i) {
                _vetor[i] *= outro._vetor[i];
            }
        } else {
            for (int i = 0; i < _tamanho; ++i) {
                _vetor[i] *= outro._vetor[i];
            }
        }
    }
    bool operator==(const VetorInt &outro) {
        if (_tamanho != outro._tamanho) {
            return false;
        } else {
            for (int i = 0; i < _tamanho; ++i) {
                if (_vetor[i] != outro._vetor[i]) {
                    return false;
                }
            }
            return true;
        }
    }
    bool operator!=(const VetorInt &outro) {
        return !operator==(outro);
    }
    int operator[](const int posicao) {
        return _vetor[posicao];
    }
    int operator()(const int posicao) {
        return _vetor[posicao];
    }
    ~VetorInt() {
        delete _vetor;
    }
protected:
    int _tamanho;
    int* _vetor;
};

#endif
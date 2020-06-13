#ifndef _DATA_H_
#define _DATA_H_

#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

class Data {
public:
    Data() : _dia(0), _mes(0), _ano(0) {}
    Data(int dia, int mes, int ano): _dia(dia), _mes(mes), _ano(ano) {}
    Data(string data) {
        _dia = atoi(data.substr(0,2).c_str());
        _mes = atoi(data.substr(3,2).c_str());
        _ano = atoi(data.substr(6,4).c_str());
    }
    int getDia() { return _dia; }
    int getMes() { return _mes; }
    int getAno() { return _ano; }
    bool operator>=(Data* outra) {
        if (_ano == outra->_ano) {
            if (_mes == outra->_mes) {
                return _dia >= outra->_dia;
            } else {
                return _mes >= outra->_mes;
            }
        } else {
            return _ano >= outra->_ano;
        }
    }
    bool operator<=(Data* outra) {
        if (_ano == outra->_ano) {
            if (_mes == outra->_mes) {
                return _dia <= outra->_dia;
            } else {
                return _mes <= outra->_mes;
            }
        } else {
            return _ano <= outra->_ano;
        }
    }
    friend istream& operator>>(istream &is, Data &data);
    friend ostream& operator<<(ostream &os, Data &data);
    ~Data() {};
private:
    int _dia;
    int _mes;
    int _ano;
};

inline istream& operator>>(istream &is, Data &data) {
    char sep;
    is >> data._dia >> sep >> data._mes >> sep >>  data._ano;
    return is;
}

inline ostream& operator<<(ostream &os, Data &data) {
    os << setfill('0') << setw(2) << data._dia << "/";
    os << setfill('0') << setw(2) << data._mes << "/" << data._ano;
    return os;
}

#endif
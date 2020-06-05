#ifndef _HORA_H_
#define _HORA_H_

#include <iostream>
#include <string>

class Hora {
public:
    Hora() : _hora(0), _minuto(0) {}
    Hora(int hora, int minuto): _hora(hora), _minuto(minuto) {}
    Hora(std::string hora) {
        _hora = atoi(hora.substr(0,2).c_str());
        _minuto = atoi(hora.substr(3,2).c_str());
    }
    friend istream& operator>>(istream &is, Hora &hora);
    friend ostream& operator<<(ostream &os, Hora &hora);
    ~Hora() {};
private:
    int _hora;
    int _minuto;
};

inline istream& operator>>(istream &is, Hora &hora) {
    char sep;
    is >> hora._hora >> sep >> hora._minuto;
    return is;
}

inline ostream& operator<<(ostream &os, Hora &hora) {
    os << setfill('0') << setw(2) << hora._hora << ":";
    os << setfill('0') << setw(2) << hora._minuto;
    return os;
}

#endif
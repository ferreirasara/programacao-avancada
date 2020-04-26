#include "VetorInt.h"
#include "Data.h"
#include <iostream>

using namespace std;

int main() {
    VetorInt vetorTeste1(5), vetorTeste2(5);

    cout << "\n++++++++++++++++++++ TESTE - VETORES ++++++++++++++++++++\n";
    cout << "\nVETORES INICIAIS\n";
    vetorTeste1.imprime();
    vetorTeste2.imprime();

    if (vetorTeste1 == vetorTeste2) {
        cout << "\nOs vetores sao iguais.\n";
    } else {
        cout << "\nOs vetores sao diferentes.\n";
    }

    VetorInt vetorAdicao = vetorTeste1 + vetorTeste2;
    VetorInt vetorSubtracao = vetorTeste1 - vetorTeste2;
    VetorInt vetorMultiplicacao = vetorTeste1 * vetorTeste2;
    VetorInt vetorEscalar = vetorTeste1 * 10;

    cout << "\nAdicao:";
    vetorAdicao.imprime();
    cout << "\nSubtracao: ";
    vetorSubtracao.imprime();
    cout << "\nMultiplicacao: ";
    vetorMultiplicacao.imprime();
    cout << "\nEscalar: ";
    vetorEscalar.imprime();

    vetorTeste1.~VetorInt();
    vetorTeste2.~VetorInt();
    vetorAdicao.~VetorInt();
    vetorSubtracao.~VetorInt();
    vetorMultiplicacao.~VetorInt();
    vetorEscalar.~VetorInt();


    cout << "\n++++++++++++++++++++ TESTE - DATAS ++++++++++++++++++++\n";
    Data dataTeste1(15, 4, 1999), dataTeste2(22, 11, 2020);
    
    cout << "\nDATAS INICIAIS" << endl;
    dataTeste1.imprime();
    dataTeste2.imprime();

    Data dataAdicao = dataTeste1 + dataTeste2;
    Data dataSubtracao = dataTeste2 - dataTeste1;

    cout << "\nAdicao: ";
    dataAdicao.imprime();
    cout << "\nSubtracao: ";
    dataSubtracao.imprime();

    if (dataTeste1 == dataTeste2) {
        cout << "\nAs datas sao iguais.\n";
    } else {
        cout << "\nAs datas sao direfentes.\n";
    }

    dataTeste1.~Data();
    dataTeste2.~Data();
    dataAdicao.~Data();
    dataSubtracao.~Data();

    return EXIT_SUCCESS;
}
#include "VetorInt.h"
#include "Data.h"
#include <iostream>

using namespace std;

int main() {
    VetorInt vetorTeste1(5), vetorTeste2(5);

    cout << "VETORES INICIAIS\n";
    vetorTeste1.imprime();
    vetorTeste2.imprime();

    VetorInt vetorAdicao = vetorTeste1 + vetorTeste2;
    VetorInt vetorSubtracao = vetorTeste1 - vetorTeste2;
    VetorInt vetorMultiplicacao = vetorTeste1 * vetorTeste2;
    VetorInt vetorEscalar = vetorTeste1 * 10;

    cout << "Adicao:\n";
    vetorAdicao.imprime();
    cout << "Subtracao:\n";
    vetorSubtracao.imprime();
    cout << "Multiplicacao:\n";
    vetorMultiplicacao.imprime();
    cout << "Escalar:\n";
    vetorEscalar.imprime();

    vetorTeste1.~VetorInt();
    vetorTeste2.~VetorInt();
    vetorAdicao.~VetorInt();
    vetorSubtracao.~VetorInt();
    vetorMultiplicacao.~VetorInt();
    vetorEscalar.~VetorInt();

    Data dataTeste1(15, 4, 1999), dataTeste2(22, 11, 2020);

    Data dataAdicao = dataTeste1 + dataTeste2;

    dataAdicao.imprime();

    return EXIT_SUCCESS;
}
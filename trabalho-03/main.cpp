#include <iostream>
#include "Conta.h"
#include "ContaCorrente.h"
#include "ContaPoupanca.h"
#include "Cliente.h"

int main() {
    cout << "CRIACAO DAS CONTAS" << endl;
    Cliente cliente1("Sara"), cliente2("Luke"), cliente3("Prince"), cliente4("Marra");
    ContaCorrente contaCliente1(1, cliente1), contaCliente2(2, cliente2);
    ContaPoupanca contaCliente3(3, cliente3), contaCliente4(4, cliente4);
    
    contaCliente1.depositaValor(5000);
    contaCliente2.depositaValor(500);
    contaCliente3.depositaValor(84.6);
    contaCliente4.depositaValor(10800);

    contaCliente1.retira(1000);
    contaCliente2.retira(50);
    contaCliente3.retira(37.4);
    contaCliente4.retira(6800);

    cout << endl << "EXTRATO APOS DEPOSITOS E RETIRADAS" << endl;
    contaCliente1.extrato();
    contaCliente2.extrato();
    contaCliente3.extrato();
    contaCliente4.extrato();
    
    contaCliente1.aplicaJurosDiarios(100);
    contaCliente4.aplicaJurosDiarios(100);

    cout << endl << "EXTRATO APOS APLICAR JUROS" << endl;
    contaCliente1.extrato();
    contaCliente4.extrato();

    return EXIT_SUCCESS;
}
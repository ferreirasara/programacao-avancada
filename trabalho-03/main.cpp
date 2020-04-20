#include <iostream>
#include <cstdlib>
#include "Conta.h"
#include "ContaCorrente.h"
#include "ContaPoupanca.h"
#include "Cliente.h"

int main() {
    cout << endl << "CRIACAO DAS CONTAS" << endl;
    Cliente cliente1("Denise"), cliente2("Pedro"), cliente3("Leandro"), cliente4("Maria");
    ContaCorrente contaCliente1(1, cliente1), contaCliente2(2, cliente2);
    ContaPoupanca contaCliente3(3, cliente3), contaCliente4(4, cliente4);
    
    for (int i = 0; i < 3; ++i) {
        contaCliente1.depositaValor(rand() % 100);
        contaCliente2.depositaValor(rand() % 100);
        contaCliente3.depositaValor(rand() % 100);
        contaCliente4.depositaValor(rand() % 100);

        contaCliente1.retira(rand() % 10);
        contaCliente2.retira(rand() % 10);
        contaCliente3.retira(rand() % 10);
        contaCliente4.retira(rand() % 10);

        cout << endl << "SALDO APOS A " << i + 1 << " ITERACAO:" << endl;
        contaCliente1.extrato();
        contaCliente2.extrato();
        contaCliente3.extrato();
        contaCliente4.extrato();
    }

    cout << endl << "TRANSFERINDO R$ 1000.00 DA CONTA 00001 PARA A CONTA 00003:" << endl;
    contaCliente1.transfere(1000, contaCliente3);
    contaCliente1.extrato();
    contaCliente3.extrato();
    
    contaCliente1.depositaValor(1000 - contaCliente1.getSaldo());
    contaCliente4.depositaValor(1000 - contaCliente4.getSaldo());

    cout << endl << "SALDO DAS CONTAS 00001 e 00004 ANTES DE APLICAR JUROS:" << endl;
    contaCliente1.extrato();
    contaCliente4.extrato();

    contaCliente1.aplicaJurosDiarios(100);
    contaCliente4.aplicaJurosDiarios(100);

    cout << endl << "SALDO DAS CONTAS 00001 e 00004 DEPOIS DE APLICAR JUROS:" << endl;
    contaCliente1.extrato();
    contaCliente4.extrato();

    // cout << endl << "EPATA 4 - VETOR COM 100 CONTAS CORRENTES" << endl;
    // Cliente clienteTeste("TESTE");
    // ContaCorrente contas[100];
    // Ocorre um erro, pq a classe ContaCorrente não tem um construtor padrão
    // Pode ser resolvido assim:
    // ContaCorrente* contas[100];
    // for (int i = 0; i < 100; ++i) {
    //     contas[i] = new ContaCorrente(i + 1, clienteTeste);
    // }
    // delete contas;

    // cout << endl << "EPATA 5 - VETOR COM 100 CONTAS" << endl;
    // Cliente clienteTeste("TESTE");
    // Conta* contas[100];
    // for (int i = 0; i < 100; ++i) {
    //     contas[i] = new ContaCorrente(i + 1, clienteTeste);
    // }
    // delete contas;

    return EXIT_SUCCESS;
}
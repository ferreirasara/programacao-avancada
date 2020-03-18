#include <iostream>

using namespace std;

int calculaPrimeiroNumero(int N) {
    return N % 3;
}

int main() {
    int N;
    cout << "Digite o valor de N: ";
    cin >> N;

    if (N < 3 || N > 10100) {
        cerr << "O valor de N deve ser um numero entre 3 e 10100. Valor digitado: " << N << endl;
        return EXIT_FAILURE;
    }

    int primeiroNumero = calculaPrimeiroNumero(N);

    if (primeiroNumero != 0) {
        cout << "O primeiro jogador deve escolher " << primeiroNumero << " para ganhar." << endl;
    } else {
        cout << "O primeiro jogador nunca vai ganhar." << endl;
    }

	return EXIT_SUCCESS;
}
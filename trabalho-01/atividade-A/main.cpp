#include <iostream>

using namespace std;

int calculaPrimeiroNumero(int N) {
    return N % 3;
}

int main(int argc, char* argv[]) {
    int N;
    cout << "Digite o valor de N: ";
    cin >> N;

    int primeiroNumero = calculaPrimeiroNumero(N);

    if (primeiroNumero != 0) {
        cout << "O primeiro jogador deve escolher " << primeiroNumero << " para ganhar.";
    } else {
        cout << "O primeiro jogador nunca vai ganhar.";
    }

	return 0;
}
#include <iostream>

using namespace std;

int calcFirstNumber(int N) {
    return N % 3;
}

int main() {
    int maxNumber;
    cout << "Digite o valor de N: ";
    cin >> maxNumber;
    

    if (maxNumber < 3 || maxNumber > 10100) {
        cerr << "O valor de N deve ser um numero entre 3 e 10100. Valor digitado: " << maxNumber << endl;
        return EXIT_FAILURE;
    }

    int firstNumber = calcFirstNumber(maxNumber);

    if (firstNumber != 0) {
        cout << "O primeiro jogador deve escolher " << firstNumber << " para ganhar." << endl;
    } else {
        cout << "O primeiro jogador nunca vai ganhar." << endl;
    }

	return EXIT_SUCCESS;
}
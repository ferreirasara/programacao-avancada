#include <iostream>
#include <iomanip>

using namespace std;

float calculaMedia(int H, int P) {
    return (float)H / P;
}

int main() {
    int H, P;
    cout << "Digite o total de cachorros-quentes: ";
    cin >> H;

    if (H < 1 || H > 1000) {
        cerr << "O total de cachorros-quentes deve ser um numero entre 1 e 1000. Valor digitado: " << H;
        return EXIT_FAILURE;
    }

    cout << "Digite o total de participantes: ";
    cin >> P;

    if (P < 1 || P > 1000) {
        cerr << "O total de participantes deve ser um numero entre 1 e 1000. Valor digitado: " << P;
        return EXIT_FAILURE;
    }

    float mediaConsumo = calculaMedia(H, P);

    cout << fixed << "Numero medio de cachorros quentes consumidos: " << setprecision(2) << mediaConsumo;

	return EXIT_SUCCESS;
}
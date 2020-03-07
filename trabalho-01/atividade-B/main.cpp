#include <iostream>
#include <iomanip>

using namespace std;

float calculaMedia(int H, int P) {
    return (float)H / P;
}

int main(int argc, char* argv[]) {
    int H, P;
    cout << "Digite o total de cachorros-quentes: ";
    cin >> H;

    cout << "Digite o total de participantes: ";
    cin >> P;

    float mediaConsumo = calculaMedia(H, P);

    cout << fixed;
    cout << "Numero medio de cachorros quentes consumidos: " << setprecision(2) << mediaConsumo;

	return 0;
}
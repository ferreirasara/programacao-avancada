#include <iostream>
#include <iomanip>

using namespace std;

float calcAvg(int H, int P) {
    return (float)H / P;
}

int main() {
    int totaOfHotDogs, totalOfParticipants;
    cout << "Digite o total de cachorros-quentes: ";
    cin >> totaOfHotDogs;

    if (totaOfHotDogs < 1 || totaOfHotDogs > 1000) {
        cerr << "O total de cachorros-quentes deve ser um numero entre 1 e 1000. Valor digitado: " << totaOfHotDogs << endl;
        return EXIT_FAILURE;
    }

    cout << "Digite o total de participantes: ";
    cin >> totalOfParticipants;

    if (totalOfParticipants < 1 || totalOfParticipants > 1000) {
        cerr << "O total de participantes deve ser um numero entre 1 e 1000. Valor digitado: " << totalOfParticipants << endl;
        return EXIT_FAILURE;
    }

    float avgConsumption = calcAvg(totaOfHotDogs, totalOfParticipants);

    cout << fixed << "Numero medio de cachorros quentes consumidos: " << setprecision(2) << avgConsumption;

	return EXIT_SUCCESS;
}
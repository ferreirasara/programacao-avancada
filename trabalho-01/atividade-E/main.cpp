#include <iostream>
#include <iomanip>

using namespace std;

int minNumberOfBlocks(int numberBlockTypes, int blockTypes[], int desiredLength) {
    return 0;
}

int main() {
    int instanceNumber;

    cout << "Numero de instancias: ";
    cin >> instanceNumber;

    for (int i = 0; i < instanceNumber; i++) {
        int numberBlockTypes, desiredLength;
        cout << "Digite o numero de tipos de blocos: ";
        cin >> numberBlockTypes;
        cout << "Digite o comprimento desejado: ";
        cin >> desiredLength;

        int blockTypes[numberBlockTypes];
        cout << "Digite cada tipo de bloco: ";
        for (int i = 0; i < numberBlockTypes; i++) {
            cin >> blockTypes[i];
        }
        cout << "Numero minimo de blocos: " << minNumberOfBlocks(numberBlockTypes, blockTypes, desiredLength) << endl;
    }
}

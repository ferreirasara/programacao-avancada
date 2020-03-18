#include <iostream>
#include <iomanip>

using namespace std;

void bubbleSort(int vetor[], int size) {
	int temp = 0;
	bool changed = false;
	for (int i = size - 1; i >= 1; i--){
		for (int j = 1; j < size; j++) {
			if (vetor[j] < vetor[j - 1]){
				temp = vetor[j];
				vetor[j] = vetor[j - 1];
				vetor[j - 1]=temp;
				changed = true;
			}
		}
		if (!changed)
			break;
	}
}

int minNumberOfBlocks(int numberOfBlockTypes, int blockTypes[], int desiredLength) {
    int minNumberOfBlocks = 0, mod, i = numberOfBlockTypes - 1;
    bubbleSort(blockTypes, numberOfBlockTypes);
    while (true) {
        mod = desiredLength % blockTypes[i];
        minNumberOfBlocks += desiredLength / blockTypes[i];
        if (mod == 0) {
            break;
        } else {
            i--;
        }
    }
}

int main() {
    int instanceNumber;

    cout << "Numero de instancias: ";
    cin >> instanceNumber;

    if (instanceNumber <= 0) {
        cerr << "O numero de instancias deve ser maior que 0. Valor digitado: " << instanceNumber;
        return EXIT_FAILURE;
    }

    for (int i = 0; i < instanceNumber; i++) {
        int numberOfBlockTypes, desiredLength;
        cout << "Digite o numero de tipos de blocos: ";
        cin >> numberOfBlockTypes;

        if (numberOfBlockTypes < 1 || numberOfBlockTypes > 25) {
            cerr << "O numero de tipos de blocos deve estar entre 1 e 25. Valor digitado: " << numberOfBlockTypes;
            return EXIT_FAILURE;
        }

        cout << "Digite o comprimento desejado: ";
        cin >> desiredLength;

        if (desiredLength < 1 || desiredLength > 1000000) {
            cerr << "O comprimento desejado deve estar entre 1 e 1.000.000. Valor digitado: " << desiredLength;
            return EXIT_FAILURE;
        }

        int blockTypes[numberOfBlockTypes];
        cout << "Digite cada tipo de bloco: ";
        for (int i = 0; i < numberOfBlockTypes; i++) {
            cin >> blockTypes[i];
        }
        cout << "Numero minimo de blocos: " << minNumberOfBlocks(numberOfBlockTypes, blockTypes, desiredLength) << endl;
    }
}

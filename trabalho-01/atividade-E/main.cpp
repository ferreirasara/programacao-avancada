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

    for (int i = 0; i < instanceNumber; i++) {
        int numberOfBlockTypes, desiredLength;
        cout << "Digite o numero de tipos de blocos: ";
        cin >> numberOfBlockTypes;
        cout << "Digite o comprimento desejado: ";
        cin >> desiredLength;

        int blockTypes[numberOfBlockTypes];
        cout << "Digite cada tipo de bloco: ";
        for (int i = 0; i < numberOfBlockTypes; i++) {
            cin >> blockTypes[i];
        }
        cout << "Numero minimo de blocos: " << minNumberOfBlocks(numberOfBlockTypes, blockTypes, desiredLength) << endl;
    }
}

#include <iostream>
#include <iomanip>

using namespace std;

int fibonacci(int n) {                                         
	if (n == 1 || n == 2) {
		return 1;	
	} else {
		return fibonacci(n - 1) + fibonacci(n - 2);	
	}	   
}

int numberOfFibonaccis(int a, int b) {
	int numberOfFibonaccis = 0;
    for (int i = 1; i > 0; i++) {
    	int fibonacciNumber = fibonacci(i);
    	if (fibonacciNumber >= a && fibonacciNumber <= b) {
    		numberOfFibonaccis++;
		} else if (fibonacciNumber > b) {
			return numberOfFibonaccis;
		}
	}
}

bool isValid(int a, int b) {
    if ((a > 0 && b > 0) && (a <= b && b <= 10100)) {
        return true;
    } else {
        return false;
    }
}

bool endOfEntry(int a, int b) {
    if (a == 0 && b == 0) {
        return true;
    } else {
        return false;
    }
}

int main(int argc, char* argv[]) {
    while (true) {
        int a, b;
        cout << "Digite o numero inicial: ";
        cin >> a;
        cout << "Digite o numero final: ";
        cin >> b;

        if (endOfEntry(a, b)) {
            return EXIT_SUCCESS;
        }
        if (isValid(a, b)) {
            int total = numberOfFibonaccis(a, b);
            cout << "Total de numeros de Fibonacci: " << total << endl;
        } else {
            cerr << "Os numeros inicial e final devem estar entre 0 e 10100, e o numero inicial deve ser menor que o numero final." << endl;
            return EXIT_FAILURE;
        }
    }
}

#include <iostream>
#include <iomanip>
#include <string>
#include <cstdlib>
#include <cmath>

using namespace std;

void decimalToHexa(int value) {
    cout << showbase << uppercase << hex << value << endl;
}

void hexaToDecimal(string value) {
    int decimalValue;
    sscanf(value.c_str(), "%x", &decimalValue);
    cout << decimalValue;
}

bool isHexa(string value) {
    if (value[0] == '0' && value[1] == 'x') {
       return true;
    } else {
        return false;
    }
}

bool isValid(int value) {
    if (value >= 0 && value < pow(2, 31)) {
        return true;
    } else {
        return false;
    }
}

int main(int argc, char* argv[]) {
    while (true) {
        string value;
        cout << "Digite um número em decimal ou hexa: ";
        getline(cin, value);
        
        if (isHexa(value)) {
            hexaToDecimal(value);
        } else {
            if (isValid(atoi(value.c_str()))) {
                decimalToHexa(atoi(value.c_str()));
            } else {
                return 0;
            }
        }
    }
}
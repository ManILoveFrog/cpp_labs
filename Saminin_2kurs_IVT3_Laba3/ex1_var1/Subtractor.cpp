#include "Subtractor.h"
#include <fstream>
#include <iostream>

double Substractor::calculate() {
    double answer = operands[0];
    for (int i = 1; i < operandsCount; i++) {
        answer -= operands[i];
    }
    return answer;
}

void Substractor::logToFile(const string& filename) {
    ofstream fout(filename, ios::app);
    fout << "\tSubstractor:" << endl;

    size_t cnt = 0;
    for (size_t i = 0; i < operandsCount; i++) {
        if (operands[i] != 0) cnt++;
    }
    operandsCount = cnt;

    fout << "Operands: " << operandsCount << endl;
    for (size_t i = 0; i < operandsCount; i++) {
        if (i == (operandsCount - 1)) {
            if (operands[i] >= 0)
                fout << operands[i];
            else
                fout << "(" << operands[i] << ")";
        }
        else {
            if (operands[i] >= 0)
                fout << operands[i] << " - ";
            else
                fout << "(" << operands[i] << ")" << " - ";
        }
    }
    fout << "\nResult: " << calculate() << "\n" << endl;
}

void Substractor::logToScreen() {
    cout << "\tSubstractor:" << endl;

    size_t cnt = 0;
    for (size_t i = 0; i < operandsCount; i++) {
        if (operands[i] != 0) cnt++;
    }
    operandsCount = cnt;

    cout << "Operands: " << operandsCount << endl;
    for (size_t i = 0; i < operandsCount; i++) {
        if (i == (operandsCount - 1)) {
            if (operands[i] >= 0)
                cout << operands[i];
            else
                cout << "(" << operands[i] << ")";
        }
        else {
            if (operands[i] >= 0)
                cout << operands[i] << " - ";
            else
                cout << "(" << operands[i] << ")" << " - ";
        }
    }
    cout << "\nResult: " << calculate() << "\n" << endl;
}

void Substractor::shuffle() {
    double temp;
    if (operands[0] >= 0) operands[0] = -operands[0];
    if (operands[operandsCount - 1] >= 0) operands[operandsCount - 1] = -operands[operandsCount - 1];
    temp = operands[0];
    operands[0] = operands[operandsCount - 1];
    operands[operandsCount - 1] = temp;

}

void Substractor::shuffle(size_t i, size_t j) {
    double temp;
    if (operands[j] >= 0) operands[j] = -operands[j];
    if (operands[i] >= 0) operands[i] = -operands[i];
    temp = operands[j];
    operands[j] = operands[i];
    operands[i] = temp;
}
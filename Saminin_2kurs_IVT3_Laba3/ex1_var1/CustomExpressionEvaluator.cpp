#include "CustomExpressionEvaluator.h"
#include <fstream> // for using file input/output
#include <iostream>

double CustomExpressionEvaluator::calculate() {
    double answer = 0;
    for (size_t i = 0; i < operandsCount; i++) {
        answer += operands[i] / ++i;
    }
    return answer;
}

void CustomExpressionEvaluator::logToScreen() {
    cout << "\tCustomExpressionEvaluator:" << endl;

    size_t cnt = 0;
    for (size_t i = 0; i < operandsCount; i++) {
        if (operands[i] != 0) cnt++;
    }
    operandsCount = cnt;

    cout << "Operands: " << operandsCount << endl;
    for (size_t i = 0; i < operandsCount; i++) {
        if (i == 0) {
            if (operands[i] > 0)
                cout << operands[i] << " + ";
            else
                cout << "(" << operands[i] << ")" << " + ";
        }
        else if (i == operandsCount - 1) {
            if (operands[i] > 0)
                cout << operands[i] << "/" << i + 1;
            else
                cout << "(" << operands[i] << ")" << "/" << i + 1;
        }
        else {
            if (operands[i] > 0)
                cout << operands[i] << "/" << i + 1 << " + ";
            else
                cout << "(" << operands[i] << ")" << "/" << i + 1 << " + ";
        }
    }
    cout << "\nResult: " << calculate() << "\n" << endl;
}

void CustomExpressionEvaluator::logToFile(const string& filename) {
    ofstream fout(filename);
    fout << "\tCustomExpressionEvaluator:" << endl;
    
    size_t cnt = 0;
    for (size_t i = 0; i < operandsCount; i++) {
        if (operands[i] != 0) cnt++;
    }
    operandsCount = cnt;

    fout << "Operands: " << operandsCount << endl;
    for (size_t i = 0; i < operandsCount; i++) {
        if (i == 0) {
            if (operands[i] > 0)
                fout << operands[i] << " + ";
            else
                fout << "(" << operands[i] << ")" << " + ";
        }
        else if (i == operandsCount - 1) {
            if (operands[i] > 0)
                fout << operands[i] << "/" << i + 1;
            else
                fout << "(" << operands[i] << ")" << "/" << i + 1;
        }
        else {
            if (operands[i] > 0)
                fout << operands[i] << "/" << i + 1 << " + ";
            else
                fout << "(" << operands[i] << ")" << "/" << i + 1 << " + ";
        }
    }
    fout << "\nResult: " << calculate() << "\n" << endl;
}

void CustomExpressionEvaluator::shuffle() {
    double temp;
    if (operands[0] >= 0) operands[0] = -operands[0];
    if (operands[operandsCount - 1] >= 0) operands[operandsCount - 1] = -operands[operandsCount - 1];
    temp = operands[0];
    operands[0] = operands[operandsCount - 1];
    operands[operandsCount - 1] = temp;

}

void CustomExpressionEvaluator::shuffle(size_t i, size_t j) {
    double temp;
    if (operands[j] >= 0) operands[j] = -operands[j];
    if (operands[i] >= 0) operands[i] = -operands[i];
    temp = operands[j];
    operands[j] = operands[i];
    operands[i] = temp;
}
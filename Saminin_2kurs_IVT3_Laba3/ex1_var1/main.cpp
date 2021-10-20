#include <iostream>
using namespace std;
#include "ILoggable.h"
#include "ExpressionEvaluator.h"
#include "CustomExpressionEvaluator.h"
#include "IShuffle.h"
#include "Multiplier.h"
#include "Subtractor.h"

int main() {
	
    double opsCustom[] = { 5, 16, -3, 10, 12 ,2 }; //massive for custom expression
    double opsSub[] = { 5.6, -2.1, 3.2, 1.5 }; //massive for subtract expression

    string filename = "log.txt";
    ExpressionEvaluator* examplesObjects[3]; // creat 3 expression

    examplesObjects[0] = new CustomExpressionEvaluator(); // first expression: custom
    examplesObjects[0]->setOperands(opsCustom, 6); // set operands by group

    examplesObjects[1] = new Substractor(); // second expression: subtract
    examplesObjects[1]->setOperands(opsSub, 4);

    examplesObjects[2] = new Multiplier(); // third expression: multiplier
    examplesObjects[2]->setOperand(0, 1.5); // set operands by elements: first operand
    examplesObjects[2]->setOperand(1, -8); // set operands by elements: second operand
    examplesObjects[2]->setOperand(2, 2.5); // set operands by elements: third operand

    for (size_t i = 0; i < 3; i++) {
        examplesObjects[i]->logToFile(filename); // output to file
        examplesObjects[i]->logToScreen(); // output to screen(console)
    }

    cout << "\n\ndo shuffle\n" << endl;
    for (size_t i = 0; i < 3; i++) {
        // use for cast pointer of class ExpressionEvaluator to pointer of class CustomExpressionEvaluator
        CustomExpressionEvaluator* customExpression = dynamic_cast<CustomExpressionEvaluator*>(examplesObjects[i]); 
        if (customExpression) {
            customExpression->shuffle(); // do shuffle by my variant's task in custom expr
            customExpression->logToScreen(); // output to screen(console)
        }
        // use for cast pointer of class ExpressionEvaluator to pointer of class Subtractor
        Substractor* substractor = dynamic_cast<Substractor*>(examplesObjects[i]);
        if (substractor) {
            substractor->shuffle(); // do shuffle by my variant's task in subtract expr
            substractor->logToScreen(); // output to screen(console)
        }
    }

	system("pause");
	return 0;
}
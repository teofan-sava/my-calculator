//
// Created by teofan on 6/24/26.
//

#include <QApplication>
#include "Calculator.h"

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    Calculator calc;
    calc.show();

    return QApplication::exec();
}

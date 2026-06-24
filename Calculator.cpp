//
// Created by teofan on 6/24/26.
//

#include "Calculator.h"
#include <QGridLayout>
#include <QVBoxLayout>

Calculator::Calculator(QWidget *parent) : QWidget(parent) {
    screen = new QLineEdit("0");
    screen->setReadOnly(true);
    screen->setAlignment(Qt::AlignRight);
    screen->setStyleSheet("font-size: 18px; height: 40px;");

    auto *layoutButtons = new QGridLayout();

    const QString tags[4][5] = {
        {"7", "8", "9", "/", "%"},
        {"4", "5", "6", "*", " "},
        {"1", "2", "3", "-", " "},
        {"0", ".", "=", "+", "C"}
    };

    for (int row = 0; row < 4; ++row) {
        for (int column = 0; column < 5; ++column) {
            QString text = tags[row][column];
            QPushButton *buton;

            if (text == "C") {
                buton = createButton(text, SLOT(deleteAll()));
            } else if (text == "=") {
                buton = createButton(text, SLOT(equalPressed()));
            } else if (text == "+" || text == "-" || text == "*" || text == "/" || text == "%") {
                buton = createButton(text, SLOT(operatorPressed()));
            } else {
                buton = createButton(text, SLOT(numberPressed()));
            }

            layoutButtons->addWidget(buton, row, column);
        }
    }

    auto *layoutPrincipal = new QVBoxLayout(this);
    layoutPrincipal->addWidget(screen);
    layoutPrincipal->addLayout(layoutButtons);

    setWindowTitle("Calculator C++");
    resize(250, 300);
}

QPushButton* Calculator::createButton(const QString &text, const char *slot) const {
    auto *button = new QPushButton(text);
    button->setMinimumSize(40, 40);
    connect(button, SIGNAL(clicked()), this, slot);
    return button;
}

void Calculator::numberPressed() {
    const auto *buttonPressed = qobject_cast<QPushButton *>(sender());
    const QString buttonValue = buttonPressed->text();

    if (buttonValue == ".") {
        if (startNewNumber) {
            screen->setText("0.");
            startNewNumber = false;
            return;
        }

        if (screen->text().contains(".")) {
            return;
        }
    }

    if (screen->text() == "0" || startNewNumber) {
        screen->setText(buttonValue);
        startNewNumber = false;
    } else {
        screen->setText(screen->text() + buttonValue);
    }
}

void Calculator::operatorPressed() {
    const QPushButton *buttonPressed = qobject_cast<QPushButton *>(sender());
    firstNumber = screen->text().toDouble();
    op = buttonPressed->text();
    startNewNumber = true;
}

void Calculator::equalPressed() {
    const double secondNumber = screen->text().toDouble();
    double result = 0.0;

    if (op == "+") result = add(firstNumber, secondNumber);
    else if (op == "-") result = subtract(firstNumber, secondNumber);
    else if (op == "*") result = multiply(firstNumber, secondNumber);
    else if (op == "/") {
        if (secondNumber == 0.0) {
            screen->setText("Error: / 0");
            startNewNumber = true;
            return;
        }
        result = divide(firstNumber, secondNumber);
    } else if (op == "%") {
        if (secondNumber == 0.0) {
        screen->setText("Error: % 0");
        startNewNumber = true;
        return;
    }
        const int firstNumberInt = static_cast<int>(firstNumber);
        const int secondNumberInt = static_cast<int>(secondNumber);
        result = modulo(firstNumberInt, secondNumberInt);
    }
    else {
        return;
    }

    screen->setText(QString::number(result));
    startNewNumber = true;
}

void Calculator::deleteAll() {
    screen->setText("0");
    firstNumber = 0.0;
    op = "";
    startNewNumber = true;
}

double Calculator::add(const double a, const double b) {
    return a + b;
}

double Calculator::subtract(const double a, const double b) {
    return a - b;
}

double Calculator::multiply(const double a, const double b) {
    return a * b;
}

double Calculator::divide(const double a, const double b) {
    return a / b;
}

int Calculator::modulo(const int a, const int b) {
    return a % b;
}
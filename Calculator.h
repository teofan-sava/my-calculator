//
// Created by teofan on 6/24/26.
//

#ifndef MY_CALCULATOR_CALCULATOR_H
#define MY_CALCULATOR_CALCULATOR_H

#include <QLineEdit>
#include <QPushButton>
#include <QString>

class QPushButton;

class Calculator : public QWidget {
    Q_OBJECT

public:
    explicit Calculator(QWidget *parent = nullptr);

private slots:
    void numberPressed();
    void operatorPressed();
    void equalPressed();
    void deleteAll();
    void functionPressed();

private:
    QLineEdit *screen;
    double firstNumber = 0.0;
    QString op = "";
    bool startNewNumber = true;

    static double add(double a, double b);
    static double subtract(double a, double b);
    static double multiply(double a, double b);
    static double divide(double a, double b);
    static int modulo(int a, int b);
    static double sine(double a);
    static double cosine(double a);

    QPushButton* createButton(const QString &text, const char *slot) const;
};

#endif //MY_CALCULATOR_CALCULATOR_H

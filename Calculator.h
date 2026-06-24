//
// Created by teofan on 6/24/26.
//

#ifndef MY_CALCULATOR_CALCULATOR_H
#define MY_CALCULATOR_CALCULATOR_H


class Calculator {
public:
    Calculator();
    ~Calculator();

    static double add(double a, double b);
    static double subtract(double a, double b);
    static double multiply(double a, double b);
    static double divide(double a, double b);
    static double modulo(int long a, int long b);
};


#endif //MY_CALCULATOR_CALCULATOR_H

//
// Created by teofan on 6/24/26.
//

#include "Calculator.h"

Calculator::Calculator() = default;
Calculator::~Calculator() = default;

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

double Calculator::modulo(const long int a, const long int b) {
    return a % b;
}
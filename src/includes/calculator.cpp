#include "../headers/calculator.h"
#include <iostream>
#include <string>

void Calculator::add(double a, double b)
{
    onStarted(CalculationStarted { "Add numbers."});
    double outcome = a+b;
    onCalculated({ std::to_string(outcome)});
}

void Calculator::sub(double a, double b)
{
    onStarted(CalculationStarted { "Sub numbers."});
    double outcome = a-b;
    onCalculated({ std::to_string(outcome)});
}

void Calculator::mul(double a, double b)
{
    onStarted(CalculationStarted { "Mul numbers."});
    double outcome = a*b;
    onCalculated({ std::to_string(outcome)});
}

void Calculator::div(double a, double b)
{
    onStarted(CalculationStarted { "Div numbers."});

    if (b == 0) {
        onError(CalculationFailed { "Cannot divide by zero."});

        return;
    }

    double outcome = a/b;
    onCalculated({ std::to_string(outcome)});
}
